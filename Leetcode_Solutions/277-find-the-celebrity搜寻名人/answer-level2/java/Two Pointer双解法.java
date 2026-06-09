基于以下两个事实：
1. 任何人都认识**名人**
2. 名人不认识**任何人**

可以知道: 
**不存在任何两个人相互不认识的情况**
所以如果我们从两端开始向内逼近检查`l, r`这两个人是否认识的话这两个指针是一定会向内逼近的，最终``l == r``, 这个人就是潜在的结果。

```
public int findCelebrity (int n) {
    int l = 0, r = n - 1;
    while (l != r) {
        if (knows(l, r)) l++;
        else r--;
    }
    // check whether l is the result
    for (int i = 0; i < n; i++) {
        if (i != l) {
            if (knows(l, i) || !knows(i, l)) return -1;
        }
    }
    return l;
}
```

其实，也可以只使用一个指针，即从头开始遍历：

```
public int findCelebrity(int n) {
    // 1. assume 0 is the celebrity
    int c = 0;
    // 2. check
    for (int i = 1; i < n; i++) {
        if (knows(c, i)) {
            // c isn't the celebrity
            c = i;
            // and anyone from [0, i-1] isn't the celebrity, because [0, i-1] must know c.
        } else {
            // i must know c, that is to say i isn't the celebrity
        }
    }

    for (int i = 0; i < n; i++) {
        if (i != c) {
            if (knows(c, i) || !knows(i, c)) return -1;
        }
    }
    return c;
}
```
