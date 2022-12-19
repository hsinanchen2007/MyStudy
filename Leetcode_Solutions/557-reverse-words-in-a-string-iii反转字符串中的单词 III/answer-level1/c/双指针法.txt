### 解题思路
此处撰写解题思路
首先编写rever函数用来反转单个单词，用指针i来遍历数组，指针j指向单词的首字母，当s[i]==' '时，i-1指向
单词的尾字母，然后rever反转单个单词，i+1赋给j并指向下一个单词首字母。
### 代码

```c
char * reverseWords(char * s){
      int i ,j,len=strlen(s);
      for(i=0,j=0;i<len;i++)
      {
          if(s[i]==' ')
          {
              rever(s,j,i-1);
              j=i+1;
          }
      }
      rever(s,j,len-1);
      return s ;  
}
void rever(char*s,int i ,int j)
{
    while(i<j)
    {
        char temp =s[j];
        s[j]=s[i];
        s[i]=temp;
        i++,j--;
    }
}
```