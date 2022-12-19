### 解题思路
方法理解起来还是挺容易的，不过就是慢。。。
### 代码

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int sum1=n*(n+1)/2;
        int sum2=0;
        for(int num:nums) sum2+=num;
        for(int i=1;i<=n;i++)
            if(count(nums.begin(),nums.end(),i)==2) {res.push_back(i);break;}
        res.push_back(res[0]+sum1-sum2);
        return res;
    }
};
```