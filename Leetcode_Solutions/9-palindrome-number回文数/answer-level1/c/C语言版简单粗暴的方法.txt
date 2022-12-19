### 解题思路
    因为只是比较整数，所以可以直接将x反转，如果反转后的数字和x相等则为回文数，如果x为负数一定不是回文数，因为负号是不可能跑到数字后面去的。
    要注意的是rev要是long型，因为rev = rev*10这步有可能溢出。
![微信截图_20200320105637.png](https://pic.leetcode-cn.com/02a015fec63ae5ffe2f194ca02771287f8072a6fef2cc33bc72b34dcf5077d26-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200320105637.png)


### 代码

```c
bool isPalindrome(int x){

    long rev = 0;
    int obv = x;
    int num = 0;

    while(x)
    {
        num = x%10;
        rev = rev*10 + num;
        x = x/10;
    }

    if(rev < 0) return false;
    else
    {
        if(rev == obv) return true;
        else return false;
    }


}
```