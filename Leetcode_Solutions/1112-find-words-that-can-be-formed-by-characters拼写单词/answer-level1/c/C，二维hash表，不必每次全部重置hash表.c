### 解题思路
如果用一维的hash表，每次换新单词时必须将hash表全部重置；
用二维hash表，多一维用来记录单词编号，当单词编号不一样时，说明换了新单词，只重置当前位的数值即可。
![image.png](https://pic.leetcode-cn.com/78bc67639a812a47c23020d2ca4862e5218e2b48432b5d7383d4e4708687e173-image.png)


### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
   int i,j,k,check,result=0,hash[26]={0},whash[2][26]={0};
   for(i=0;chars[i]!='\0';i++){
       j=(int)(chars[i]-'a');
       hash[j]++;
   }
   for(i=0;i<wordsSize;i++){
       check=1;
       for(j=0;words[i][j]!='\0';j++){
           k=(int)(words[i][j]-'a');
           if(whash[1][k]!=i){
               whash[0][k]=1;
               whash[1][k]=i;
           }else whash[0][k]++;
           if(hash[k]<whash[0][k]){
               check=0;
               break;
           }
       }
       if(check==1) result+=j;
   }
   return result;
}
```