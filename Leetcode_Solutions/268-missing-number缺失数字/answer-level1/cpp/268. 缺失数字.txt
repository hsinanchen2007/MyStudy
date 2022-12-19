具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/268.missing_number)  

```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp=0;
        for(int i=1;i<=nums.size();i++)
            temp ^=i^nums[i-1];
        return temp;
    }
};
```

> 执行用时 : 28 ms, 在Missing Number的C++提交中击败了93.78% 的用户  
内存消耗 : 9.9 MB, 在Missing Number的C++提交中击败了17.85% 的用户