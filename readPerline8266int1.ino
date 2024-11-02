#include <Wire.h>
#include <Math.h>
#include <SPI.h>
#include <SD.h>
File myFile; // สร้างออฟเจก File สำหรับจัดการข้อมูล
const int CSpin = D1 ; // 4 chipSelect = 6

////////  variable 
int countlinech = 1 , numlinech = 1  ;  
double numeral1 = 0.0 , numeral2 = 0.0 ;
////////  char part1 and part2 , string part1 and part 2 ////
char ctext1[1000] ; // amount of char more
String  textforstr1 ;
unsigned int lineNumber , a1 ;

   // void InitializeSDcard();

void setup(){
 pinMode(CSpin, OUTPUT);
 Serial.begin(9600); 
  InitializeSDcard(); 
} // end setup 

void loop(){
 //open a file
 ///////   set line to read per line ////////////////////
 numlinech = 7 ; ///   number of line
 OpenFile("testread1.txt");
 Serial.print("open file TESTREAD1.txt") ;
 Serial.print("\n");
   //  show all data in file txt  
   // String list = myFile.readStringUntil('\r');
    Serial.print("number of line = ");
    Serial.print(numlinech) ;
    Serial.print("  ");
    Serial.print("printLineNla() = ");
    printLineNla(numlinech) ;
    Serial.print("\n");
////  bring string in function 
   Serial.print(" textforstr1 = ");
   Serial.print( textforstr1 );
   Serial.print("\n");
 //// convert string to double  for calculation  
    numeral1 = textforstr1.toDouble() ;
    numeral2 = numeral1 + 0.211 ;
   Serial.print(" Test String to Double , numeral1 + 0.211 = ");
   Serial.print(numeral2, 3 );
   Serial.print("\n");

    delay(3000) ;


}   /// END void Loop 


//// only InitializeSDcard 
void InitializeSDcard(){
  Serial.println("Opening SD Card . . .");
  delay(500);
  if(SD.begin(CSpin))
  {
    Serial.println("SD Card ready to use");
  }else{
    Serial.println("Failed to open SD Card");
    return;
  }
}

//// function Open file 
int OpenFile(char Filename[]){
  myFile = SD.open(Filename, FILE_WRITE);
  myFile = SD.open(Filename, FILE_READ);
  delay(500);
  if(myFile)
  {
    Serial.println("File is open");
    return 1;
  }else{
    Serial.println("Error opening file");
    return 0;
  }
}

//// Print Line number one line 
/////////  printline Latitude ////////
void printLineNla(unsigned int lineNumber){
  myFile.seek(0);
  char cr;  
  for(unsigned int i = 0; i < (lineNumber -1);){
    cr = myFile.read() ;
    if(cr == '\n'){
      i++;
    }
  }  
  //Now we are at the right line
  int t = 0 ;
  while(true){
    cr = myFile.read();
    Serial.write(cr);
        ctext1[t] = cr ;
     if(cr == '\n'){
       textforstr1 = String(ctext1) ; // send read per line to string
      break;
    }
    t = t+1 ;
  }
  //a for loop with a read limit might be a good idea

}// End  void printLineN

