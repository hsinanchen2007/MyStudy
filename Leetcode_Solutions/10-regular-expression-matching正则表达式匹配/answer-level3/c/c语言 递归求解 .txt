### 解题思路
此处撰写解题思路
运用了递归
### 代码

```c
bool matchStar(int i,int j, char * s, char * p);

bool isMatch(char * s, char * p){


return matchStar(0,0,s,p);

}

 bool matchStar(int i,int j, char * s, char * p)
 {

if(s[i]=='\0'&&p[j]=='\0') return true;
 if(s[i]!='\0'&&p[j]=='\0') return false;

 if(s[i]=='\0'&&p[j]!='\0') 
 {
    if(p[j+1]=='*') return matchStar(i,j+2,s,p);
    else return false;
 }


 else if(p[j+1]=='*')
{
     if(p[j]=='.'||s[i]==p[j])
    {
        return matchStar(i+1,j,s,p)||matchStar(i,j+2,s,p);    //可以选择匹配or不匹配
    
    }

     else
    {
        return matchStar(i,j+2,s,p);
    }
}

else {

  if(p[j]=='.'||s[i]==p[j])
  {
      return matchStar(i+1,j+1,s,p);
  }
  else return false;


}

 }








```