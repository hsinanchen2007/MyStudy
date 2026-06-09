### 解题思路

![image.png](https://pic.leetcode-cn.com/631a75917c479e5b6a33ca12077d631592d6f0ecc45d11372d6bfac125964179-image.png)


深度优先搜索
去重（剪枝）的操作：
1.每次dfs时从当前的start_index开始往后遍历,让它可以再选择一次自己。
  如果题目是不能选择重复的，就从start_index+1开始往后遍历
2.每次遍历的时候，可能会有重复的 比如[2,3,3,3,4,5]里面的3，因此用一个now_num来记录，让指针继续往后滑，即
while(i<candidates.size()-1 && candidates[i+1]==now_num) i++;
这个时候不建议使用while(i<candidates.size() && candidates[i]==now_num) i++;来滑，因为外面还有一层for循环，会让i多加一次。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<int>& candidates,int start_index, int target){
        if(target==0){
            res.push_back(tmp);
        }
        if(target<0) return;

        for(int i=start_index;i<candidates.size();i++){
            int now_num = candidates[i];
            while(i<candidates.size()-1 && candidates[i+1]==now_num) i++;
            tmp.push_back(now_num);
            dfs(candidates,i,target-now_num);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        if(n==0) return res;
        dfs(candidates,0,target);
        return res;
    }
};
```