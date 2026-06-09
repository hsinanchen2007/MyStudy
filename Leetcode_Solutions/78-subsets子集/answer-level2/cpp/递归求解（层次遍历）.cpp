### 解题思路
可以分析 
当子集为 {1}时，
添加2后，变成 {1},{1,2},{2}
添加3后，变程 {1},{2},{1,2},{1,3},{2,3},{1,2,3} {3}
所以推倒出，每次添加一个新元素时，都把原来的节点重新拷贝然后在加上这个新元素，最后在加上这个新元素。
这个有点类似层次遍历的

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    void addcur(vector<int>& nums,int cur)
    {
        if(cur >= nums.size()) return;
        int len = res.size();
        vector<int> vec(1,nums[cur]);
        res.push_back(vec);
        for(int i=0;i< len;i++)
        {
           vector<int> vec(res[i]);
           vec.push_back(nums[cur]);
           res.push_back(vec);
        }
        addcur(nums,cur+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        if(nums.size() == 0) {
            res.push_back(vec);
            return res;
        }
        addcur(nums,0);
        res.push_back(vec);
        return res;
    }
};
```