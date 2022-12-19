遍历2次：
第一次：将连续了3个相同字符以上的字符串首尾字符赋值为‘#’
第二次：将含有‘#’的位置顺序遍历二维化。
```
int** largeGroupPositions(char * S, int* returnSize, int** returnColumnSizes){
      int i=1;
      int count=1;
      int index=0;
      int num=0;
      while(S[i]!='\0')
      {   
          if(S[i]==S[i-1])
              count++;
          else
          {
              if(count<3)
              {
                  index=i;
                  count=1;
              }
              else
              {
                  S[index]='#';
                  S[i-1]='#';
                  index=i;
                  count=1;
                  num++;
              }
          }
          i++;
      }
      if(count>=3)
      {
         S[index]='#';
         S[i-1]='#';
         num++;
      }
      *returnSize=num;
      int**H=(int**)malloc(num*sizeof(int*));
      *returnColumnSizes=(int*)malloc(num*sizeof(int));
      for(int j=0;j<num;j++)
      {
          H[j]=(int*)malloc(2*sizeof(int));
          (*returnColumnSizes)[j]=2;
      }
      count=0;
      for(i=0;S[i]!='\0';i++)
      {
          if(S[i]=='#')
          {
              H[count/2][count%2]=i;
              count++;
          }
      }
      return H;
}
```