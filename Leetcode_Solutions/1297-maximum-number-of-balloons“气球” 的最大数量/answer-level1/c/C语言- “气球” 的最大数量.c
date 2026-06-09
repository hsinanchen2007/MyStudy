### 解题思路

统计出现次数
### 代码

```c
int maxNumberOfBalloons(char * text){
    int record[5]={0},i,min;
    for(i=0;i<strlen(text);i++){
        if(text[i]=='a')record[0]++;
        if(text[i]=='b')record[1]++;
        if(text[i]=='l')record[2]++;
        if(text[i]=='n')record[3]++;
        if(text[i]=='o')record[4]++;
    }
    min=record[0];
    record[2]=record[2]/2;
    record[4]=record[4]/2;
   
    for(i=1;i<5;i++)if(min>record[i])min=record[i];
    return min;
}
```