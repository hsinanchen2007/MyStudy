```
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> n3;
        int n2=INT_MIN;
        for(int i=nums.size()-1;i>=0;--i)
        {
            int now=nums[i];
            if(now<n2)return true;
            while(!n3.empty() && now>n3.top())
            {
                n2=n3.top();
                n3.pop();
            }
            n3.push(now);
        }
        return false;
    }
};
```
