### 解题思路
先将数组排序，使相同的数字放置在相邻的位置上

判重：
nums[1],...nums[k],nums[k+1],nums[k+2],....

如果 k>0&&nums[k]==nums[k-1]&&!used[k-1] ，说明前一种情况回溯完成，下一种情况会导致重复，需跳过

比如 set=[1,2^,2^^]
cur=[]
cur=[1]
cur=[1,2^]
cur=[1,2^,2^^] 回溯
cur=[1,2^] 回溯
cur=[1]  
**注意到此时前一种情况回溯完成，即将开始下一情况,即cur=[1,2^^]的情况，由于数字的重复，再向下计算会导致和cur=[1,2^]的情况重复，因此跳过 continue 再回溯**
cur=[]
cur=[2^]
cur=[2^,2^^] 回溯
cur=[2^] 回溯
cur=[]
**注意到此时前一种情况回溯完成，即将开始下一情况,即cur=[2^^]的情况，由于数字的重复，再向下计算会导致和cur=[2^]的情况重复，因此跳过，结束**

![90.JPG](https://pic.leetcode-cn.com/e73f15123dc3cced30decf203fa1d2dd67d9c3c1215ced5402b32c2445d9f0be-90.JPG)

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
            return;
        }
        for(int k=start;k<n;k++){
            if(!used[k]){
                if(k>0&&nums[k]==nums[k-1]&&!used[k-1])
                   continue;
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
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        if(n==0){
            res.push_back(cur);
            return res;
        }
        used=vector<bool>(n,false);
        sort(nums.begin(),nums.end());
        subset(nums,0,0);
        return res;
    }

};
```