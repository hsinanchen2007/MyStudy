思路：
1、新建一个临时数组temp，让数组后k个元素依次放入，被放入temp数组中的值从nums中删除
2、利用双指针方法，让temp倒序排列
3、nums剩余值放入temp后面
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        k = k % nums.size();
        for(int i = 0; i < k; i++){
            temp.push_back(nums[nums.size() - 1]);
            nums.pop_back();//删除已被移动过的
        }
        for(int i = 0; i < k/2; i ++) {
            swap(temp[i], temp[k - i -1]);//翻转
        }
        temp.insert(temp.end(), nums.begin(), nums.end());//合并
        nums = temp;
    }
};
```