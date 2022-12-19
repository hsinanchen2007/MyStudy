### 解题思路
击败100%

### 代码

```c


bool isValid(char * s){
    if(!s){return true;}
    if(s[0]==')'||s[0]==']'||s[0]=='}'){return false;}
    
    char*stack=(char*)malloc(sizeof(char)*(strlen(s)+1));
    int i,j=1; 
    for(i=0;s[i];i++)
    {
        if(stack[0]==')'||stack[0]==']'||stack[0]=='}'){return false;}
        if(s[i]=='('||s[i]=='['||s[i]=='{')
        {
            stack[j++]=s[i];
            continue;
        }
   
        if((s[i]==')'&&stack[j-1]=='(')||( s[i]==']'&&stack[j-1]=='[')||( s[i]=='}'&&stack[j-1]=='{')){
            j--;
        }else{
            return false;
        }
           
    }
    if(j==1)
    {
        return true;
    }else{
        return false;
    }
}


```