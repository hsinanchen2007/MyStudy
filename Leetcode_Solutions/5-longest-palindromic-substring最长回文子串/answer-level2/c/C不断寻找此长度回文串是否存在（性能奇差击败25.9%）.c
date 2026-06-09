### 解题思路
从最长到2，看该长度的回文串是否存在，存在就建新数组赋值输出
最后只能长度为1的，建一个赋值首字母输出即可

### 代码

```c
bool isRol(char *s,int start,int end);
char * longestPalindrome(char * s){
    int n = strlen(s);   // s[0]->s[n-1]

    if(n<=1) return s;
    int large ;
    
    for(large=n;large>1;large--) //逐个寻找是否存在 large长度的回文子串。
    {
        //可以寻找的子串范围起点，从0->(n-large)
        for(int i=0;i<=n-large;i++)
        {
            if(isRol(s,i,i+large-1)) 
            {
                char *p = (char*)malloc(sizeof(char)*(large+1));
                for(int num=0;num<large;num++)
                {
                    p[num]=s[i++];
        
                }
                p[large]='\0';
                return p;
            }
        }
    }

    char *little = (char*)malloc(sizeof(char)*2);
    little[0]=s[0];
    little[1]='\0';
    return little;

}

bool isRol(char *s,int start,int end)  //验证s在 start 到 end 之间是否是回文子串
{
    while(start<end)
    {
        if(s[start]!=s[end]) return false;

        start++;
        end--;
    }
    return true;
}
```