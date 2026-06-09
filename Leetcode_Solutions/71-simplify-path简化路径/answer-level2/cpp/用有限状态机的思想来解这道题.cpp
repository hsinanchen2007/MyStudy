> 最近在按 Tag 来刷之前做过的题目，然后在刷 Stack Tag 的时候刷到了这道题，然后想出来的就是常见的“分割字符串+栈”的解法。因为之前刷的时候每刷完一道题就会写一遍博客，然后我就发现了我之前的解法尽量和现在的解法完全不同。以下内容搬运自我一年前的[博客](https://blog.codeand.fun/2019/03/02/Simplify-Path/)。


对于这种纯看逻辑的题目，可以先分析一下给出的测例，然后通过题目来分析要注意什么：

1. "/home/"
2. "/../"
3. "/home//foo/"
4. "/a/./b/../../c/"
5. "/a/../../b/../c//.//"
6. "/a//b////c/d//././/.."

从上面我们大概可以知道要注意的一些点有：

- 首先疑似最开始的符号一定是'/'？
- 通过`/`来分割单词，这意味着我们可以用`python`中的`split`或者先做一次遍历来分割单词，这样做会简化逻辑（但我没用这种方法）
- 要区分`.`和`..`
- `.`表示当前目录，`..`表示上级目录
- 遇到多个`/`，就当成一个

事实上在后面的测试中，我发现一个很坑的点，就是`...`和`..a`这种并不是一个特殊的字符串，可以作为路径名。

我们现在尝试写一个基于状态机的方法，首先定义一下遍历时需要的状态：


0. 前面是一个正常的字符
    - 遇到`/`,就插入到结果字符串中，并跳转到`1`。
    - 遇到`.`，就跳转到`2`。
    - 遇到一个正常的字符，插入到结果字符串中。
1. 前面是`/`
    - 如果遇到一个`/`，就直接跳过
    - 如果遇到一个`.`,跳转到`2`
    - 如果是一个正常字符，就插入到结果字符串中并跳转到`0`
2. 前面是`.`
    - 如果遇到一个`/`, 就跳转到`1`
    - 如果遇到一个`.`,就跳转到`3`
    - 如果遇到一个正常字符，就插入`.`和这个字符，并跳转到`0`
3. 前面是`..`
    - 如果遇到一个`/`,就开始回溯删除到前面一个`/`
    - 其余则插入一个`..`和这个字符，并跳转到`0`


状态转移图如下：


![FSM](https://pic.leetcode-cn.com/24a35460f64a52399272f5f720a881d12f675a6c86f6dd4d28b106d58158d8c9-svg.svg)


```c++
class Solution {
public:
    string simplifyPath(string path) {
        string res;
        
        // some flag to kepp state.
        int state = 0;  // 0: last char is [char]
                        // 1: last char is '/'
                        // 2: last char is '.'
                        // 3: last char is ".."
        
        if (path.size() != 0 && path[path.size()-1]!='/') path.push_back('/');
        
        int len = path.size();
        for(int i = 0; i < len; i++) {
            char c = path[i];
            
            if (state == 0) {
                if (c == '/') { res.push_back('/'); state = 1; }
                else if (c == '.') state = 2;
                else res.push_back(c);
            } else if (state == 1) {
                if (c == '/') {}
                else if (c == '.') { state = 2; }
                else {
                    res.push_back(c); state = 0;
                }
            } else if (state == 2) {
                if (c == '/') state = 1;
                else if (c == '.') {
                    // '..'
                    state = 3;
                } else {
                    res.push_back('.'); res.push_back(c); state = 0;
                }
            } else if (state == 3) {
                if (c == '/') {
                    // go back
                    res.pop_back(); // pop '/'
                    while(res.size() != 0 && *res.rbegin() != '/') {
                        res.pop_back(); // pop anthing until '/'
                    }
                    if (res.size() == 0) res.push_back('/');
                    state = 1;
                } else {
                    res.push_back('.'); 
                    res.push_back('.');
                    res.push_back(c);
                    state = 0;
                }
            }
            //cout << state << " " << c << " " << res <<  endl;
        }
        
        if ((state == 1 && res.size() != 1)) res.pop_back();
        return res;
    }
};
```