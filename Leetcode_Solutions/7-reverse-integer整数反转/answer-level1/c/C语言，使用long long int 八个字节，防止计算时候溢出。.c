### 解题思路
此处撰写解题思路

### 代码

```c
int reverse(int x){
        int max = 2147483647, min =-2147483648;
        //int result;//result用4个字节时，测试2147483646  会有溢出
        long long result=0;//在16位和32位操作系统中，long占4个字节。long long八个字节，不会有溢出
        while(x!=0)
        {
            result=result*10+x%10;
            x=x/10;

        }

        return result>max||result<min? 0:result;
        //return result; //只是测试

}
```