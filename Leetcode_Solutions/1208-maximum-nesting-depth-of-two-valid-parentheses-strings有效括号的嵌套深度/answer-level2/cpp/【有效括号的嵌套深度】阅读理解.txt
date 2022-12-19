### 分析
1. 给出的叫做**有效括号字符串**的 `string seq` ，保证其中只有 `(` `)` ，并且是有效的（左右匹配）
2. 深度 `depth` 表示这个字符串括号嵌套的深度
    21. 如果是嵌套的就加深
    22. 如果是前后连接的，就取 `max`
3. 子序列的意思是，前后顺序不能变，但是可以跳着选自己想要的
4. 前面都是概念讲解，这道题真正问的是：

**给你一个有效括号字符串，把它按子序列的方式分成两个有效括号字符串，并使它们两个深度最小**

### 举例
```
输入：seq = "(())"
输出：[0,1,1,0]
```

1. 比如这个例子 `(())` ，深度是 2 
2. 要按照子序列的方式拆成两个字符串，拆完肯定是 `()` `()` ，拆了之后每个字符串的深度都是 1
    21. 答案不唯一，有可能是 [0,1,1,0]
    22. 也有可能是 [0,1,0,1]
    23. 或者 1 和 0 反过来也行

### 思路
1. 在经历了很长时间的阅读理解之后，我冒出的第一个想法就是
2. 先使用括号套路————堆栈 `stack` ，算出原来的深度
3. 再使用括号套路————堆栈 `stack` ，把深度超过一半的部分全都分出来
4. 虽然代码很长操作略显麻烦，但是非常利于理解

### 图解
![图片.png](https://pic.leetcode-cn.com/9a548e2e64074dbd03ede567b7ea19cb1148bd7fdf448d856f83c0417b2aa4b6-%E5%9B%BE%E7%89%87.png)


### 答题
```C++ []
vector<int> maxDepthAfterSplit(string seq)
{
    vector<int> ans(seq.size(), 0);
    int d = 0;
    stack<int> st;
    for (int i = 0; i < seq.size(); i++)
    {
        d = max(d, (int)st.size());
        if (seq[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
        }
    }
    for (int i = 0; i < seq.size(); i++)
    {
        int j = 0;
        if (seq[i] == '(')
        {
            st.push(i);
        }
        else
        {
            j = st.top();
            st.pop();
        }
        if (st.size() < d / 2)
        {
            ans[i] = 1;
            ans[j] = 1;
        }
    }
    return ans;
}
```

### 优化
1. 考虑只是拆分成 2 部分，不一定按照深度的一半来区分
2. 使用奇偶层来区分，即可在一次遍历完成
3. 另外括号套路也可以使用优化版，使用计数替代堆栈

```C++ []
vector<int> maxDepthAfterSplit(string seq) 
{
    vector<int> ans(seq.size(), 0);
    int d = 0;
    for (int i = 0; i < seq.size(); i++)
    {
        if (seq[i] == '(') 
        {
            ans[i] = d % 2;
            d++;
        }
        else
        {
            d--;
            ans[i] = d % 2;
        }
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

