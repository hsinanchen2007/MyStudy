### 解题思路
计算出两个字符串的长度lena、lenb，设置进位标志carry；由于可能产生进位，结果字符串的长度设置为较大字符串长度加一，考虑到字符串末尾的结束符标志，分配内存时长度加一，初始化最高位为‘0’，手动添加字符串末尾结束符'\0'；从后向前遍历连个字符串并判断是否有进位情况，若最高位为‘0’,则最高位没有进位，将字符串整体迁移一位，并添加字符串结束标志'\0'，返回字符串ans

### 代码

```c
char *addBinary(char * a,char * b){
    int len, lena=strlen(a), lenb=strlen(b), carry=0, i=lena-1, j=lenb-1,k,num;
    len=lena>lenb?lena+1:lenb+1;
    char* ans=(char*)malloc(sizeof(char)*(len+1));
    ans[0]='0';
    ans[len]='\0';
    k=len-1;
    while(i>-1||j>-1||carry){
        num=(i>-1?a[i]-'0':0)+(j>-1?b[j]-'0':0)+carry;
        carry=0;
        if(num>1){
            carry=1;
            num=num-2;
        }
        ans[k--]=num+'0';
        j--;
        i--;
    }
    if(ans[0]=='0'){
        for(i=0; i<len-1;i++)
            ans[i]=ans[i+1];
        ans[len-1]='\0';      
    }
    return ans;
}
```