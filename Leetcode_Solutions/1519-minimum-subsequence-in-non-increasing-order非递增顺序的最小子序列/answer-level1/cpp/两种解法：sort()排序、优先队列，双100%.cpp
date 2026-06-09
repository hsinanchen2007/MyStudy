### 优先队列
优先队列，取出队列中前的最大值，和剩余之和比较。

### 代码

```cpp
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        priority_queue <int,vector<int>,less<int> > q;
        vector<int> res;
        int sum1=0,sum2=0;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            sum1+=nums[i];
        }

        while(sum2<=(sum1-sum2)){
            sum2+=q.top();
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
```

&nbsp;
### sort()
```
class Solution {
public:
    int sum1=0,sum2=0;
    vector<int> ans;
    vector<int> minSubsequence(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
        }
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        int i=0;
        while(!nums.empty()&&sum2<=sum1-sum2){
            ans.push_back(nums[i]);
            sum2+=nums[i];
            i++;
        }
        return ans;
    }
};
```
