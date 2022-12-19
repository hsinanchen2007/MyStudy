### 解题思路
此处撰写解题思路

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
int m,n,i,j,k,count=0;
m=strlen(chars);
if(m==0)
return 0;
int*signal=(int*)malloc(sizeof(int)*m);
for(i=0;i<m;i++)
signal[i]=0;
for(i=0;i<wordsSize&&words[i][0]!='\0';i++){
    n=strlen(words[i]);
    for(j=0;j<n;){        //只有在找到时候，j++
        for(k=0;k<m;k++){
            if(words[i][j]==chars[k]&&signal[k]==0)     //signal[0]代表第一次出现
            {signal[k]=1;
             break;
            }    
        }
        if(k<m) j++;       //在chars数组中找到了words[i][j],j++;若在chars数组中没找到words[i][j],直接break;
        else break;
   }
   for(k=0;k<m;k++){
        if(signal[k]==1){
        if(j==n)
         count++;
         signal[k]=0;
         }
      }
}
return count;
}
```