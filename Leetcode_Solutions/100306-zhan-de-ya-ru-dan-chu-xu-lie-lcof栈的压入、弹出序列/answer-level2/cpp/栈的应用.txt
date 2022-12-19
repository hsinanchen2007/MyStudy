```C++ []
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // 设置两个数组的游标
        int i = 0;
        int  j = 0;
        stack<int> stk;
        // 首先依次将压入序列入栈
        while(i<pushed.size())
        {
            // 判断压入数字是否与当前弹出数字相等，若相等，则栈顶元素弹出
            while(!stk.empty())
            {
                if(stk.top() == popped[j])
                {
                    stk.pop();
                    j++;
                }
                else
                    break;
            }
            // 若栈顶元素与当前弹出数字不相等，继续压入栈
            if(i<pushed.size())
            {
                stk.push(pushed[i]); 
                i++;
            }
        }
        // 等压入序列全部入栈，再逐个比较栈顶元素与弹出数字是否相等
        while(!stk.empty())
        {
            if(stk.top() == popped[j])
            {
                stk.pop();
                j++;
            }
            else
                break;
        }
        // 若弹出序列的游标已经等于其长度，说明全部弹出序列都比较完毕
        if(j == popped.size())
            return true;
        else
            return false;

    }
};
```


