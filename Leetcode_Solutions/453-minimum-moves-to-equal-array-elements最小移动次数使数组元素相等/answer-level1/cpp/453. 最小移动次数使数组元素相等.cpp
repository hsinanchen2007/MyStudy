具体[见此](https://newdee.gitbook.io/leetcode/leetcode-index/453.minimum_moves_to_equal_array_elements)  

```
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int res=0;
       int  minimum=*min_element(nums.begin(),nums.end());
        for(auto i: nums)
            res +=i-minimum;
        return res;
    }
};
```



> 执行用时 : 52 ms, 在Minimum Moves to Equal Array Elements的C++提交中击败了93.27% 的用户  
内存消耗 : 10.8 MB, 在Minimum Moves to Equal Array Elements的C++提交中击败了85.59% 的用户