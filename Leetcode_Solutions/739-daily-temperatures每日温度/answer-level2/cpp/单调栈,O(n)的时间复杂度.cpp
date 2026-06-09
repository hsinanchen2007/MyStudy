我发现单调栈真的是很巧妙的工具。之前在柱状图最大矩形面积一题中接触到单调栈，就有意识地记住这种数据结构。做到这题，发现能用得上，并且很简单。  
用一个单调栈，栈中元素是温度数组的下标，对应的温度是非递增的。对于要加入栈的温度T[i],把T[i]和stk.top()对应的温度比较，要保持栈的单调递减特性，对于被弹出的栈顶元素top,则T[i]是T[top]后第一个温度高于自己的温度，那么结果数组的第top个元素就是i - top。  
最后，栈非空的话，说明栈中元素之后的日期没有温度高于自己的，在结果数组中都是0。   
```
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int len = T.size();
        vector<int> ret(len);
        stack<int> stk; //存idx
        for (int i = 0; i < len; ++i)
        {
            while ((stk.empty() == false) && (T[stk.top()] < T[i]))
            {
                ret[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        while (stk.empty() == false)
        {
            ret[stk.top()] = 0;
            stk.pop();
        }
        return ret;
    }
};
```