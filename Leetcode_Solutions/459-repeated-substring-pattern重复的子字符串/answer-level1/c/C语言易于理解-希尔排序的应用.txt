### 解题思路
考虑希尔排序的步长，按照这个步长把字符串分为几等份。d=len/2为初始值，如果len%d!=0的话，这个d一定不满足
如果len%d==0，我们就可以把字符串分为len/d等份，用[0,d-1]这一段的字符串与后面的去匹配，匹配成果则返回true，否则d--,直到d==1还匹配不成功的话，则返回false
### 代码

```c
bool repeatedSubstringPattern(char * s){
    int len=strlen(s);
    int d=len/2;
    int count=0;
    int i=0,j;
    for(;d>=1;d--){
        if(len%d!=0)
            continue; 
        else{
            count=1;
            while(count<len/d){
            for(i=0,j=count*d;i<d&&j<len;i++,j++){
                if(s[i]!=s[j])
                    break;
            }
            if(i>=d)
                count++;
            else
                break;
            }
            if(count>=len/d)
                return true;
        }
    }
    return false;
}
```