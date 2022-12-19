### 解题思路
数组存储，注意**用long接收结果**，否则用int的话会越界。

### 代码

```c
bool isPalindrome(int x){
    int res[32];
    int i=0;
    long result=0;
    int init=x;//需要保留原来的数字
    while(x>0){
        res[i]=x%10;
        x=x/10;
        i++;
    }
    for(int k=0;k<i;k++){
        result=result*10+res[k];
    }
    if(init==(int)result) return true;
    else return false;
}




```