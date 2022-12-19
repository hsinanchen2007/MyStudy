### 解题思路 
此处撰写解题思路
0、两个字符串长度不相等的时候不是亲密字符串；
1、字符串长度为0时不是亲密字符串；
2、当两个字符串长度相等时，分别遍历两个字符串，只有两个字符串完全相等时||只有两处字符不相等
时才有可能是亲密字符串，其余情况不是亲密字符串。
（0）当两个字符串完全相等时，其中任意一个字符串中有重复字符时是亲密字符串，否则不是。
（1）只有两处字符不相等时，必须满足A[i]==B[j]&&A[j]==B[i]时是亲密字符串，否则不是。

### 代码

```c
bool buddyStrings(char * A, char * B){
  int len1=strlen(A),len2=strlen(B);
  if(len1!=len2||len1==0||len2==0)
  return false ;
  else
  {
      int i ,j,num=0,count1,count2;
      for(i=0;i<len1;i++)
      {
          if(A[i]!=B[i])
          {
              num++;
              if(num==1)
              count1=i;
              if(num==2)
              count2=i; 
          }
      }
      if(num==0)
      {
          for(i=0;i<len1;i++)
           for(j=i+1;j<len1;j++)
           {
               if(A[i]==A[j])
               return true ;
           }
           return false ;
      }
      else if(num==2)
      {
          if(A[count1]==B[count2]&&A[count2]==B[count1])
          return true ;
          else
          return false;
      }
      else
      return false ;
  }
}
```