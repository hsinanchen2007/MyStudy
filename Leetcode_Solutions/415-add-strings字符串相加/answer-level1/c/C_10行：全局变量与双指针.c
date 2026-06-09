### 解题思路
同两数之和链表相加一样，其实可以不用移位，非要让数组第一个开头，可以直接返回指针，只要保证字符串结尾有`'\0'`就不会报错。

![image.png](https://pic.leetcode-cn.com/4fa55408cd4be4649e2c6ba63515c335a42cc80f30bf16eb643bd1250164a21f-image.png)


### 代码一、全局开res[5103]
因为最大可能就是两个都是5100个9，进位最多产生2个位，因此加上末尾的`'\0'`那么够多了。
**注意**：不能开函数体内，因为里面`res[5103]`栈内存，虽然这个够小完全可以开，但是返回返回结束就小时，再次访问可能是`NULL`或者报错。解决办法在函数体内用关键字`static char res[5103]`，这跟下面代码放在全局是一样的。
```c
char res[5103] = {'\0'};
char * addStrings(char * num1, char * num2){
    short s1 = strlen(num1), s2 = strlen(num2), len = 5101, carry = 0;
    for (s1--, s2--; s1 >= 0 || s2 >= 0 || carry;) {
        carry += (s1 >= 0 ? num1[s1--] - 48: 0) + (s2 >= 0 ? num2[s2--] - 48 : 0);  // 最长遍历处理
        res[len--] = carry % 10 + 48;
        carry /= 10;
    }
    return &res[len+1];  // 返回指针，取地址
}
```

### 代码二、动态申请：堆内存
```c
char * addStrings(char * num1, char * num2){
    short s1 = strlen(num1), s2 = strlen(num2);
    short maxlen = s1 > s2 ? s1 : s2;
    char *res = (char *)malloc(sizeof(char) * (maxlen + 3));
    res[maxlen+2] = '\0';  // 从最后开始计算
    short carry = 0;
    for (s1--, s2--,maxlen=maxlen+1; s1 >= 0 || s2 >= 0 || carry;) {
        carry += (s1 >= 0 ? num1[s1--] - 48: 0) + (s2 >= 0 ? num2[s2--] - 48 : 0);
        res[maxlen--] = carry % 10 + 48;
        carry /= 10;
    }
    return &res[maxlen+1];
}
```

这个还没有上面好，内存跟上面差不多。。