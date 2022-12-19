### 解题思路


### 代码


char * numberToWords(int num){
if (!num)
return "Zero";


int i,unitNum;
char * unit[4]={"Billion","Million" ,"Thousand",""};
int nums[4]={1000000000,1000000,1000,1};
char *englishNum=(char*)malloc(256);
strcpy(englishNum,"");
for(i=0;i<4;i++)
{
    unitNum=num/nums[i];
    
    if(unitNum==0)
    continue;
    int j=1000;
    int tenflag=0;
    while(j!=0){
   switch(unitNum/j){
    case 9: 
    if(tenflag){
    strcat(englishNum,"Nineteen");
    tenflag=0;
    }
    else
    strcat(englishNum,j==10? "Ninety":"Nine");
    strcat(englishNum,(j!=1||i!=3)?" ":"");
    break;
    case 8:
    if(tenflag){
    strcat(englishNum,"Eighteen");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Eighty":"Eight");
     strcat(englishNum,(j!=1||i!=3)?" ":"");break;
    case 7:
    if(tenflag){
    strcat(englishNum,"Seventeen");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Seventy":"Seven");strcat(englishNum,(j!=1||i!=3)?" ":"");break;
    case 6:
    if(tenflag){
    strcat(englishNum,"Sixteen");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Sixty":"Six");strcat(englishNum,(j!=1||i!=3)?" ":""); break;
    case 5:
    if(tenflag){
    strcat(englishNum,"Fifteen");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Fifty":"Five");strcat(englishNum,(j!=1||i!=3)?" ":""); break;
    case 4:
    if(tenflag){
    strcat(englishNum,"Fourteen");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Forty":"Four");strcat(englishNum,(j!=1||i!=3)?" ":"");break;
    case 3:
    if(tenflag){
    strcat(englishNum,"Thirteen");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Thirty":"Three");strcat(englishNum,(j!=1||i!=3)?" ":"");break;
    case 2:
    if(tenflag){
    strcat(englishNum,"Twelve");
    tenflag=0;
    }
    else
     strcat(englishNum,j==10?"Twenty":"Two");strcat(englishNum,(j!=1||i!=3)?" ":"");break;
    case 1:
    if(tenflag){
    strcat(englishNum,"Eleven ");
    tenflag=0;
    }
    else
    { 
    if(j==10){
    tenflag=1;
    }
    else{
     strcat(englishNum,"One");
     strcat(englishNum,((j!=1||i!=3))?" ":""); 
    }}
   break;
   case 0:
   if(tenflag){
    strcat(englishNum,"Ten ");
    tenflag=0;
    }
    default: break;
}
     if(unitNum/j!=0 && j==100)
         strcat(englishNum,"Hundred ");
    unitNum=unitNum%j;
    j=j/10;
}
     if(num/nums[i]!=0){
         strcat(englishNum,unit[i]);
         if(i!=3)
         strcat(englishNum," ");
     }
    num=num%nums[i];
}

if (englishNum[strlen(englishNum) - 1] == ' '){
        englishNum[strlen(englishNum) - 1] = '\0';
    }

    return englishNum;
}




