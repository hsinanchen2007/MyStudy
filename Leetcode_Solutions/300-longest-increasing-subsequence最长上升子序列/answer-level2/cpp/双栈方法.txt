方法纯属靠瞎猜，猜对了😂。
这个方法我是从使用一个栈开始的，有部分示例无法通过。
然后加入了栈S2，但是和栈不同的是，S2只记录升序，只有当S2.size()<S.size()，将S拷贝给S2并继续遍历数组。


```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }

        int res = 1;
        int _size = 0;
        stack<int> S,S2;
        for(auto el:nums){
            
            while(S.size()>0 && S.top()>=el){
                S.pop();
            }
            S.push(el);
            if(S2.size()==0 || el>S2.top()){
                S2.push(el);
            }
            if(S2.size()<S.size()){
                S2=S;
            }
            _size = std::max(S.size(),S2.size());
            res= std::max(res,_size);
        }


        return res;
    }
};
```

