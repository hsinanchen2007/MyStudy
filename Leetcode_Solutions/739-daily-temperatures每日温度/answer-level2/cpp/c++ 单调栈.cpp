```
//单调栈 从后往前遍历
//如果栈里没有元素 代表没有一天比它温度高 
//然后将该元素入栈
//如果栈里有元素 若栈顶元素比现在的元素大 则栈顶元素就是 第一个比该元素高的元素
//若栈顶元素比它小 一直pop到栈顶元素比它大 或栈为空为止
//然后该元素入栈

//由于需要记录 需要过几天 所以栈中多存储一个下标字段
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> s;
        int len=T.size();
        vector<int> res(len);
        for(int i=len-1;i>=0;i--)
        {
            while(!s.empty()&&s.top().first<=T[i])
                s.pop();
            if(s.empty())res[i]=0;
            else res[i]=s.top().second-i;
            s.push(make_pair(T[i],i));
        }
        return res;
    }
};
```
