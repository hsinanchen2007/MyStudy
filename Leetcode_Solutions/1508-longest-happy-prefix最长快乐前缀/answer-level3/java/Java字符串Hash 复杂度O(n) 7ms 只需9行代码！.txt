![](https://pic.leetcode-cn.com/dcc1f623bd2d36ae9ab91d376a560b3c09b30e4703e92c37fd74cb980201d627.png)

$$
Hash = s[0]*31^{n-1}+s[1]*31^{n-2}+...+s[i]*31^{n-i-1}+...+s[n-2]*31^1+s[n-1]
$$				

关于为什么哈希值计算乘数为31，说法是，首先31是质数，其次编译器会将31*i 优化为 (i<<5)-i
			
```java
// 本质上就是循环比较前缀与后缀是否相等
// 利用substring equals会超时
// 利用字符串hash值来进行比较，每次也不需要重新计算
// 对于前缀 hash = hash*31 + 新添头字符ch
// 对于后缀 hash = hash + 新添尾字符*31^t   (t为后缀长度减1)
// 有几次提交结果是12ms 不知道是什么原因
public String longestPrefix(String s) {
    int len = s.length();
    char chars[] = s.toCharArray();
    int max = 0, iHash = 0, jHash = 0, times = 1;
    for(int i=1; i<len; i++,times*=31){
        iHash = iHash*31 + chars[i-1];
        jHash += chars[len-i]*times;
        if(iHash==jHash)    max = i;
    }
    return s.substring(0,max);
}
```

