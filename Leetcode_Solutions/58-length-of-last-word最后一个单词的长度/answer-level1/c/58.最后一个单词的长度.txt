### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLastWord(char * s){
     int i,len=0,cnt=0;
     for(i=0;s[i]!='\0';i++)
        len++;
    if(len>0){
        i=len-1;
        while(i>=0){
            if(s[i]==' ')
            i--;
            else{
                for(;i>=0&&s[i]!=' ';i--)
                cnt++;
                break;
            }
        }
    }
     return cnt;
}
```