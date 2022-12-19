### 解题思路
（1）本题采用栈比较容易解决：对左半边括号采取入栈操作，右半边括号和栈顶进行对比，如果不一致则说明有问题
（2）这里采用malloc而不是vector是因为动态数组占用空间会更大，不如精确分配
（3）如果不free的话执行速度会更少，但是这不符合安全代码的原则。而且free会减少内存消耗
### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) 
            return true;   

        int top = 0;       
        char *stack = (char*)malloc(s.size()); 
        for (int i = 0; s[i]; ++i) 
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
                stack[top++] = s[i];
            else 
            {
                if ((--top) < 0)            
                    return false;
                if (s[i] == ')' && stack[top] != '(') 
                    return false;
                if (s[i] == ']' && stack[top] != '[') 
                    return false;
                if (s[i] == '}' && stack[top] != '{') 
                    return false;
            }
        }
        free(stack);
        return (!top);
    }
};
```