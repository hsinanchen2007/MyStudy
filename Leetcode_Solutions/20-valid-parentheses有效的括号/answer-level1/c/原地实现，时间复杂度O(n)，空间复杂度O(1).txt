不知道为啥，总感觉题解里的C解法都好复杂的样子，又是栈，又是数组的。我个人感觉直接原地就行了，不知道是不是考虑不周了。
放下执行结果：
![image.png](https://pic.leetcode-cn.com/bdb60cf657e605ee4f789c6149a571f3625016d6c6591bd3cb175c3b9fa4d773-image.png)


总感觉leetcode加了注释的代码好丑，先放一份没注释的代码，带注释的代码见更下一段代码
## 不带注释的代码
```
bool isValid(char * s){
    int low = -1, high = 0;

    while (s[high] != '\0') {
        if (s[high] == '(' || s[high] == '[' || s[high] == '{') {
            s[++low] = s[high++];
        } else if (low >= 0
                    && (s[high] - 1 == s[low] || s[high] - 2 == s[low])) {
            --low;
            ++high;
        } else {
            return false;
        }
    }

    return low == -1;
}
```

## 带注释的代码
```
bool isValid(char * s){
    int low = -1, high = 0; // 两个指针，low用于模拟栈，high往后遍历数据

    while (s[high] != '\0') {
        // 如果是'(', '[', '{'，则模拟入栈
        if (s[high] == '(' || s[high] == '[' || s[high] == '{') {
            s[++low] = s[high++];
        // 如果栈非空，且站定元素和当前遍历到的元素是对应的括号，则模拟出栈
        } else if (low >= 0 
                    // 这里这么写是因为，查了下ascii码，'('和')'差1，'['和']','{''}'差2
                    && (s[high] - 1 == s[low] || s[high] - 2 == s[low])) {
            --low;
            ++high;
        } else {
            // 栈顶元素和当前遍历到的元素不一致，则fasle
            return false;
        }
    }

    // 若栈为空，则true，否则false
    return low == -1;
}
```
