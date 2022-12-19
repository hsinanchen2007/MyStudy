### 解题思路
参考了[用时 99.93%，内存98.73%，简单解法](https://leetcode-cn.com/problems/roman-to-integer/solution/yong-shi-9993nei-cun-9873jian-dan-jie-fa-by-donesp/)
其中的一句“当没有下一位时，做加法即可。” 很有想法，也就是说s的最后一位(s[strlen(s)-1])直接加到sum中即可：
![1.png](https://pic.leetcode-cn.com/c3dbad76a09b6c46b4178a4ca208a4326131ba31a094c515811672c0b22a74f4-1.png)

但是为什么他的用时和内存比我的优秀很多，感觉我和他的差不多耶。

我也想过用大小写表示每一位是加还是减，虽然没有最后采用，但是过程中还是学会了[C语言小写转大写，小写字母转换成大写字母](http://c.biancheng.net/view/569.html)
uppercase lowercase
总结起来就是：大写字母+32=小写字母 (小写>大写，大32)

### 代码

```c
int getValue(char val){
    switch(val){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;    
    }
    
}
int romanToInt(char * s){
    int cur,fut,sum=0;
    int i;
    for(i=0;i+1<strlen(s);i++){
        cur=getValue(s[i]);
        fut=getValue(s[i+1]);
        if(cur<fut) sum-=cur;
        else sum+=cur;
    }
    sum+=getValue(s[strlen(s)-1]);
    return sum;

}
```