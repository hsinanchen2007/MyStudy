我没用数组和链表，我感觉也挺快的，不知道是不是我的错觉哈
![微信图片_20200315125711.png](https://pic.leetcode-cn.com/896cde86f87098b225514abae4f1001492d324be3ff77712f757cf9dec95dc3e-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200315125711.png)
用时12s击败78%，内存5.5MB，击败100%

```
bool isPalindrome(int x){
    long w=1,g=10,n=0;
    int i;
    if(x<0)
        return false;
    while(x/w != 0){
        w=w*10;
        n++;
    }
    w = w/10; //找最高位
    for(i=0;i<n/2;i++){
        if(x/w!=x%g) //最高位和最低位比较
            return false;
        else{
            x=(x%w)/g; //去掉最高位和最低位
            w = w/100; //去掉两位，所以w缩小100
        }
    }
    return true;

}
```
先用最高位和最低位比较，再把最高位和最低位去掉，再次循环比较。

