思路很简单，每次插入的数是数量最多的那个字符，但是如果这个字符已经在最近的两次都出现了，
就换成第二多的那个字符，
注意一下循环结束的条件：另外两个字符的数量都是0了，而且最近两次d字符相同，均等于剩下的那个字符
那就退出循环了

char * longestDiverseString(int a, int b, int c){
if(a==0&&b==0&&c==0)
return "";
char *res=(char *)malloc(sizeof(char)*(a+b+c+2));
int n=0;
while(true)
{
      if(a==0&&b==0&&c==0)
      break;
      else if(a==0&&b==0&&n>=2&&res[n-1]==res[n-2]&&res[n-1]=='c')
      break;
      else if(b==0&&c==0&&n>=2&&res[n-1]==res[n-2]&&res[n-1]=='a')
      break;
      else if(a==0&&c==0&&n>=2&&res[n-1]==res[n-2]&&res[n-1]=='b')
       break;
      else{
      if(a>=b&&a>=c)
    {
        if((n<2||(res[n-1]!='a'||res[n-2]!='a'))&&a>0)
       {res[n++]='a';
        a--;
        }
        else if(b>c&&b>0)
        {res[n++]='b';
        b--;}
        else if(c>0)
        {res[n++]='c';
        c--;}
        continue;
     }
     else if(b>=a&&b>=c)
     {
        if((n<2||(res[n-1]!='b'||res[n-2]!='b'))&&b>0)
        {res[n++]='b';
        b--;}
        else if(a>c&&a>0)
        {res[n++]='a';
        a--;}
        else if(c>0)
        {res[n++]='c';
        c--;}
        continue;
     }
     else
     {
        if((n<2||(res[n-1]!='c'||res[n-2]!='c'))&&c>0)
        {res[n++]='c';
        c--;}
        else if(a>b&&a>0)
        {res[n++]='a';
        a--;}
        else if(b>0)
        {res[n++]='b';
        b--;}
        continue;
     }
     }
}
res[n]='\0';
return res;
}