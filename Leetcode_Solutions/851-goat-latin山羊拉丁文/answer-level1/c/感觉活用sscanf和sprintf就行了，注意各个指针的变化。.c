### 解题思路
此处撰写解题思路

### 代码

```c
char * toGoatLatin(char * S){
    char* result=(char*)malloc(sizeof(char)*10000);
    char temp[1000];
    int num=0,position=0,templength=0;
    while (sscanf(&S[templength],"%s",temp)!=-1){
        //printf("%s",temp);
        templength=templength+ strlen(temp)+1;
        num++;
        if (temp[0]=='a'||temp[0]=='A'||temp[0]=='e'||temp[0]=='E'||temp[0]=='i'||temp[0]=='I'||temp[0]=='o'||temp[0]=='O'||temp[0]=='u'||temp[0]=='U'){
            sprintf(&result[position],"%sma",temp);
            position=position+strlen(temp)+2;
            for (int i=0;i<num;i++){
                sprintf(&result[position],"a");
                position++;
            }
            sprintf(&result[position]," ");
            position++;
        } else{
            sprintf(&result[position],"%s%cma",&temp[1],temp[0]);
            position=position+strlen(temp)+2;
            for (int i=0;i<num;i++){
                sprintf(&result[position],"a");
                position++;
            }
            sprintf(&result[position]," ");
            position++;
        }       
    }
    result[position-1]='\0';
    return result;
}
```