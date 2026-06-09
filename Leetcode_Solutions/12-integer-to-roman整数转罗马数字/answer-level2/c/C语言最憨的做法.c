### 解题思路
此处撰写解题思路

### 代码

```c

char * intToRoman(int num)
{
    int ThBit = 0, HuBit = 0, TenBit = 0, Bit = 0;
    int array[4] = { 0 };
    char Roman[20]={0x0};
    char uRoman[20]={0x0};
    char* cRoman = Roman;
    int count = 0;
    while (num != 0)
    {
        array[count] = num % 10;
        num /= 10;
        count++;
    }
    switch (count)
    {
    case 4:
        Bit = array[0];
        TenBit = array[1];
        HuBit = array[2];
        ThBit = array[3];
        break;
    case 3:
        Bit = array[0];
        TenBit = array[1];
        HuBit = array[2];
        break;
    case 2:
        Bit = array[0];
        TenBit = array[1];
        break;
    case 1:
        Bit = array[0];
        break;
    }
    for (ThBit; ThBit != 0; ThBit--)
    {
            int i = 0;
            uRoman[i] = 'M';
            strcat(Roman, uRoman);
            i++;
    }
    switch (HuBit)
    {
    case 9:
        uRoman[0] = 'C';
        uRoman[1] = 'M';
        uRoman[2]='\0';        
        uRoman[3]='\0'; 
        strcat(Roman, uRoman);
        break;
    case 8:
        uRoman[0] = 'D';
        uRoman[1] = 'C';
        uRoman[2] = 'C';
        uRoman[3] = 'C';
        strcat(Roman, uRoman);
        break;
    case 7:
        uRoman[0] = 'D';
        uRoman[1] = 'C';
        uRoman[2] = 'C';     
        uRoman[3]='\0'; 
        strcat(Roman, uRoman);
        break;
    case 6:
        uRoman[0] = 'D';
        uRoman[1] = 'C';
        strcat(Roman, uRoman);
        break;
    case 5:
        uRoman[0] = 'D';
        uRoman[1]='\0'; 
        uRoman[2]='\0';        
        uRoman[3]='\0'; 
        strcat(Roman, uRoman);
        break;
    case 4:
        uRoman[0] = 'C';
        uRoman[1] = 'D';
        uRoman[2]='\0';        
        uRoman[3]='\0'; 
        strcat(Roman, uRoman);
        break;
    case 3:
        uRoman[0] = 'C';
        uRoman[1] = 'C';
        uRoman[2] = 'C';     
        uRoman[3]='\0';         
        strcat(Roman, uRoman);
        break;
    case 2:
        uRoman[0] = 'C';
        uRoman[1] = 'C';
        uRoman[2]='\0';        
        uRoman[3]='\0'; 
        strcat(Roman, uRoman);
        break;
    case 1:
        uRoman[0] = 'C';
        uRoman[1]='\0'; 
        uRoman[2]='\0';        
        uRoman[3]='\0';         
        strcat(Roman, uRoman);
        break;
    case 0:
        break;
    }
    switch(TenBit)
    {
        case 9:
        uRoman[0]='X';
        uRoman[1]='C';
        uRoman[2]='\0';        
        uRoman[3]='\0';         
        strcat(Roman,uRoman);
        break;
        case 8:
        uRoman[0]='L';
        uRoman[1]='X';
        uRoman[2]='X';
        uRoman[3]='X';            
        strcat(Roman,uRoman);
        break;
        case 7:
        uRoman[0]='L';
        uRoman[1]='X';
        uRoman[2]='X'; 
        uRoman[3]='\0';         
        strcat(Roman,uRoman);
        break;
        case 6:
        uRoman[0]='L';
        uRoman[1]='X';
        uRoman[2]='\0';        
        uRoman[3]='\0';         
        strcat(Roman,uRoman); 
        break;
        case 5:
        uRoman[0]='L';
        uRoman[1]='\0'; 
        uRoman[2]='\0';        
        uRoman[3]='\0';         
        strcat(Roman,uRoman);    
        break; 
        case 4:
        uRoman[0]='X';
        uRoman[1]='L';
        uRoman[2]='\0';        
        uRoman[3]='\0'; 
        strcat(Roman,uRoman);  
        break;   
        case 3:
        uRoman[0]='X';
        uRoman[1]='X';
        uRoman[2]='X';  
        uRoman[3]='\0';         
        strcat(Roman,uRoman);  
        break;
        case 2:
        uRoman[0]='X';
        uRoman[1]='X';
        uRoman[2]='\0';        
        uRoman[3]='\0'; 
        strcat(Roman,uRoman);  
        break;
        case 1:
        uRoman[0]='X';
        uRoman[1]='\0'; 
        uRoman[2]='\0';        
        uRoman[3]='\0';         
        strcat(Roman,uRoman);  
        break;
        case 0:
        break;                    
    }
    switch(Bit)
    {
        case 9:
        uRoman[0]='I';
        uRoman[1]='X';
        uRoman[2]='\0';
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;
        case 8:
        uRoman[0]='V';
        uRoman[1]='I';
        uRoman[2]='I';
        uRoman[3]='I';
        strcat(Roman,uRoman);
        break;
        case 7:
        uRoman[0]='V';
        uRoman[1]='I';
        uRoman[2]='I';
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;
        case 6:
        uRoman[0]='V';
        uRoman[1]='I';
        uRoman[2]='\0';
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;  
        case 5:
        uRoman[0]='V';
        uRoman[1]='\0';
        uRoman[2]='\0';        
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;         
        case 4:
        uRoman[0]='I';
        uRoman[1]='V';
        uRoman[2]='\0';
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;               
        case 3:
        uRoman[0]='I';
        uRoman[1]='I';
        uRoman[2]='I';        
        uRoman[3]='\0';        
        strcat(Roman,uRoman);   
        break;      
        case 2:
        uRoman[0]='I';
        uRoman[1]='I';    
        uRoman[2]='\0';
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;    
        case 1:
        uRoman[0]='I';
        uRoman[1]='\0'; 
        uRoman[2]='\0';        
        uRoman[3]='\0';        
        strcat(Roman,uRoman);
        break;                        
    }
    return cRoman;
}
```感觉我是真的骚