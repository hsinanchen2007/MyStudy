### 解题思路
1.使用s存储数组中所有的数字并去除重复数字。
2.再遍历一边数组，把不在set中的元素加入result容器中

### 代码

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> result;
    set<int> set_nums;

    for(int i = 0;i < nums.size();i++){
        set_nums.insert(nums[i]);
    }

    for(int i = 1;i < nums.size() + 1;i++){
        if(set_nums.find(i) == set_nums.end()){
            result.push_back(i);
        }
    }
    return result;
    }
};
```