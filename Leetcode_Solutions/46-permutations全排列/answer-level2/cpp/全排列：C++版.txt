### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    // 方法二
    void backtrack(vector<int>& nums, vector<vector<int>>& output, int first){
        if(first == nums.size()){ // 若交换完所有值后，表明递归到树的叶子
            output.push_back(nums);
        }
        // 此方法的巧妙在于使用swap方法调换数字的位置，
        // 再使用first可以规定从哪一位开始，避免了使用bool数组和路径数组
        for(int i = first; i < nums.size(); i++){ 
            int tmp = nums[i]; // 交换值
            nums[i] = nums[first];
            nums[first] = tmp;

            backtrack(nums, output, first + 1); // 递归树状回溯

            tmp = nums[i];    // 交换回来
            nums[i] = nums[first];
            nums[first] = tmp;
        }
    }
    // 方法二
    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> output;
        backtrack(nums, output, 0); // 从第一个数开始交换
        return output;
    }
    // 方法一
    void backtrack(vector<int>& nums, vector<vector<int>>& output, vector<int>& path, bool used[], int depth){
        if(depth == nums.size()){
            output.push_back(path);
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == false){
                used[i] = true;          // 将此位标志位设为 已访问
                path.push_back(nums[i]); // 将此位添加到路径里
                backtrack(nums, output, path, used, depth + 1);  // 深度加 1
                path.pop_back();        //  回溯路径
                used[i] = false;        //  将此位标志位重置为 未访问
            }
        }
    }
    // 方法一
    vector<vector<int>> permute(vector<int>& nums){ // 使用bool数组记录访问的位数，并且使用path记录路径
        vector<vector<int>> output;
        vector<int> path;
        bool* used = new bool[nums.size()]{0}; // 要初始化为全false
        backtrack(nums, output, path, used, 0);
        return output;
    }
};
```