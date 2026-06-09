# 每日温度
### 栈



### 分析：
由题意可知，输入为一个温度列表`temperatures`，要根据该列表计算出**每一天到下一次气温升高所需等待的天数**并存储到一个列表中。此处关心的是**最近一次气温升高**。
而在解决某个问题时，**只要求关心最近一次的操作，并且操作完成后，需要向前查找到更前一次的操作时**，采用**栈**解决问题。

### 思路1：（从前往后）：
申请一个与`T`大小相同的向量并初始化为0；
创建一个栈用于存储下标，再通过下标index从前往后遍历温度列表`T`
1. 当栈空或index所指的温度不高于栈顶元素所指温度时，将index压入栈
2. 否则，**用index减去栈顶元素**得出**下一次温度升高所需等待的天数**，并存储到ans下标为**栈顶元素**处。
3. 遍历完如果栈不空，则温度列表中的最后几天一直没有等待到温度上升，而ans初始化时均为0，所以可以不做处理

### 代码
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) 
    {
       	vector<int> sqstack;
        vector<int> ans(T.size(), 0);
        int index = 0;
        int top = 0;
        while (index < T.size())
        {
            if ((sqstack.empty()) || (T[index] <=  T[sqstack.back()]))//未找到下一次温度升高，入栈
            {
                sqstack.push_back(index++);
            }
            else//找到对于栈顶元素来说下一次升高的时候，算出所需等待天数并存入对应位置，栈顶元素出栈
            {
                ans[sqstack.back()] = index - sqstack.back();
                sqstack.pop_back();

            }
        }
        return ans;
    }
};  
```




### 思路2：（从后往前）：
申请一个与`T`大小相同的向量并初始化为0；
创建一个栈用于存储下标，再通过下标index从后往前遍历温度列表`T`
1. 如果栈不空且index所指温度大于栈顶元素所指温度，栈顶一直元素出栈，直到其中一个条件不满足
2. 此时，分为两种情况，栈空，或index所指温度大于栈顶元素所指温度
    1. 栈空，则令`ans[index]=0`，由于初始化为0，此时可以不操作
    2. index所指温度小于栈顶元素所指温度，**栈顶元素就是index之后下一次温度上高的时候**，**用栈顶元素减去index，得出对于index来说下一次温度升高所需等待的天数，并存在`ans[index]`中

### 代码：
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector <int> ans (T.size(), 0);
        stack <int> sqstack;
        for(int i = T.size()-1; i >= 0; --i)
        {
            while(!sqstack.empty() && T[i] >= T[sqstack.top()]) sqstack.pop();//找下一次温度升高的时候
            if(!sqstack.empty())//栈不空，即找到下一次温度升高的时候
                 ans[i] = sqstack.top() - i;//算出下一次温度升高所需等待的天数，并存储到对应位置
                //栈空，则没有下一次温度升高的时候，由于初始化为0，此时可以不操作
            sqstack.push(i);
        }
        return ans;
    }
};
```