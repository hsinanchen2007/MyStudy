### 解题思路
1.首先计算a|b,如果正好等于c，直接返回0即可；
2.补充一个知识点，如果想要判断一个整数x（二进制）的第n位(第0位开始))是1还是0，则只需要计算(x&(1<<n))>>n即可
3.一个正整数有32位，除去31位，还剩下第0-30位
4.从第30位开始到第0位，计算这些位上a,b,c是0还是1，用x,y,z表示，如果x|y!=z,那么分情况:
  z=1时，那么x,y一定全是0，count加2
  z=0时，x,y有一个是1,count就加1


### 代码

```c
int minFlips(int a, int b, int c){
    if ((a|b)==c)
        return 0;
    int a_binary,b_binary,c_binary,i,count=0;
    i = 30;
    while(i>=0){
        a_binary = ((a&(1<<i))>>i);
        b_binary = (b&(1<<i))>>i;
        c_binary = (c&(1<<i))>>i;
        if ((a_binary|b_binary)!=c_binary){
            if (c_binary==1)
                count++;
            else{
                if (a_binary)
                    count++;
                if (b_binary)
                    count++;
            }
        }
        i--;
    }
    return count;
}
```