### 解题思路
头一次知道string还有pop_back和push_back，以及可以直接比较两个string是否相等

用栈很方便，但是写代码的时候一定要注意下文的注释

### 代码

```cpp
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string stack1 = "", stack2 = "";
        for(auto c:S)
            if(c=='#' && stack1.size())
                stack1.pop_back();
            else if(c!='#')//这里一定要判断一下c是否是#，因为c=='#' && stack1.size()的否命题是c!='#' || !stack1.size()
                stack1.push_back(c);
        
        for(auto c:T)
            if(c=='#'&&stack2.size())
                stack2.pop_back();
            else if(c!='#')
                stack2.push_back(c);
        
        return stack1==stack2;

    }
};
```