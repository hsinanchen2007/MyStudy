把放数据想象成数据多叉树深搜，
nums[i+1]指向下一个数据Node。
每次搜索深度都是nums.size()。

![image.png](https://pic.leetcode-cn.com/72a74f44af705630190ea254406e57ac3491d3b6dae4d98a549b13504a210d75-image.png)

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back({});
        DFS(0, nums, {});
        return result;
    }
private:
    vector<vector<int>> result;
    void DFS(int i, vector<int> &nums, vector<int> &&item){
        if(i>=nums.size()){
            return;
        }
        DFS(i + 1, nums, PushBack(item, nums[i]));
        result.push_back(item);
        DFS(i + 1, nums, PoPBack(item));
    }

    vector<int> PushBack(vector<int> &item,int num){
        item.push_back(num);
        return item;
    }
    vector<int> PoPBack(vector<int> &item){
        item.pop_back();
        return item;
    }
};

```
