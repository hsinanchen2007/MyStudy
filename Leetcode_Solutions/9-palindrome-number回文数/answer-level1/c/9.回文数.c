### 解题思路
最开始用了最麻烦的思路，想要直接确定位数，然后依次判断，但是问题也出现了，最核心的问题就是代码效率很低，并且如何实现逐位判断也是复杂的事。
后来看了官方给出的代码，发现了可以直接对折判断就可以实现了。

### 代码

```c
bool isPalindrome(int x){
    if(x < 0||(x % 10 == 0 && x!=0) ) return false;
    int resultNumber=0;
    while(resultNumber < x){
        resultNumber = resultNumber * 10 + x % 10;//这里是x%10 取当前x的最后一位
        x = x / 10;//没更新一次resultNumber，就相应地要改变一次x
    }
    if(resultNumber == x || x == resultNumber/10)
        return true;
    else
        return false;
    
}
```

### 总结
关于"/"和"%"两个符号的区别。
如：x = 101，那么x / 10 = 10；（取整） x % 10 = 1(取余)