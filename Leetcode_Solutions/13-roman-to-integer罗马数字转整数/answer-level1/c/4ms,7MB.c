#include <string.h>

int romanToInt(char * s){
    

    int num = 0;
    for(int i = 0;s[i]!='\0';i++)
    {
        if(s[i] == 'I')
        {
            num = num+1;
            if(s[i+1] == 'V' || s[i+1] == 'X')
            num = num-2;  //   
        }
        if(s[i] == 'V')
        {
            num = num+5;
    
        }
        if(s[i] == 'X')
        {
           
            num = num+10;
            if(s[i+1] == 'L' || s[i+1] == 'C')
            num = num-20;
        }
        if(s[i] == 'L')
        {
            num = num+50;
           
        }
        if(s[i] == 'C')
        {
            num = num+100;
            if(s[i+1] == 'D' || s[i+1] == 'M')
            num = num-200;
           
        }
        if(s[i] == 'D')
        {
            num = num+500;
            
        }
        if(s[i] == 'M')
        {
            num = num+1000;
            
        }
    }
    

    
    return num;
    

}