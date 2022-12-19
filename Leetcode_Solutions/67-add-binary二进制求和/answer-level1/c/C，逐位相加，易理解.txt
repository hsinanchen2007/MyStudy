### 解题思路
设置一个比a,b最大长度大1的字符数组str，将a,b逐位的和与进位相加结果为ans，高位的进位为ans求商，低位的结果为ans求余，重复直到a,b其中一个数组结束，将剩下数组和进位相加重复上述操作。最后如果进位为1，最高位为1，返回str，否则返回str+1。

### 代码

```c


char * addBinary(char * a, char * b){
    int n=strlen(a),m=strlen(b);
    if(n<m)     //保证a为最长数组，减少了后面判断的次数
        return addBinary(b,a);
    int max_l=n,carry=0,ans;
    char *str=(char*)malloc(sizeof(char)*(n+2));    
    str[n+1]='\0';      //刚开始一直执行出错，非法访问，最后看别人的才发现数组最后需要一个结束字符（用devc++就不需要判断，可能和leetcode编译器相关）
    while(m){
        ans=a[--n]-'0'+b[--m]-'0'+carry;    //c语言里没有直接将字符转为整数的函数（可能有但我不知道，希望知道的说一下）
        str[max_l--]=ans%2+'0';
        carry=ans/2;
    }
    while(n){
        ans=a[--n]-'0'+carry;
        str[max_l--]=ans%2+'0';
        carry=ans/2;
    }
    if(carry){
        str[max_l]='1';
        return str;
    }
    else
        return str+1;
}


```