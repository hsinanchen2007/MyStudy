### 解题思路
为使子集不重复，按 nums[ ] 中的顺序每次将nums的一个元素 nums[k] 作为子集的第一个元素，遍历该情况下所有的可能性，其中元素只能在 nums[k+1],nums[k+2],....nums[nums.size()-1] 中取。

set: [1,2,3]
subset: [[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]

![leetcode78题解.JPG](https://pic.leetcode-cn.com/2369d1194b6d638b64da99d5bb42d8657d0bf812a0471ba746183cddd2d58d45-leetcode78%E9%A2%98%E8%A7%A3.JPG)

### 代码

```cpp
class Solution {
public:
    int n;
    vector<int> cur;
    vector<bool> used;
    vector<vector<int>> res;
    
    //子集的元素个数为i,可用元素从nums[start]开始
    void subset(vector<int>& nums,int i,int start){
        if(i>n||start>=n) return;
        if(cur.size()==i){
            res.push_back(cur);
            subset(nums,i+1,0);
        }
        for(int k=start;k<n;k++){
            if(!used[k]){
                used[k]=true;
                cur.push_back(nums[k]);
                if(cur.size()==i){
                    res.push_back(cur);
                    subset(nums,i+1,k+1);
                    used[k]=0;
                    cur.pop_back();
                }  
            }
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        used=vector<bool>(n,false);
        subset(nums,0,0);
        return res;
    }
};
```