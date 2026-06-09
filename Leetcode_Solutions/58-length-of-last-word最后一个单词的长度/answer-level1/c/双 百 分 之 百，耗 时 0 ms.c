### 解题思路
此处撰写解题思路
从字符串中倒数第一个字符遍历，并用flag做标记，while flag==1时，代表空格字符出现在最后一个单词之前，
flag==0时代表空格字符出现在最后一个单词之后，从最后一个字符开始遍历，当遍历到字母时，用num记数，直到遍历到空格时，返回num值。
### 代码

```c
int lengthOfLastWord(char * s){
  int i,len=strlen(s);
  int num=0,flag=0;
  for(i=len-1;i>=0;i--)
  {
      if(s[i]!=' ')
       {
           num++;
           flag=1;
       }
      else
      {
          if(flag==1)
          return num ;
      } 
  }
  return num ;
}
```