### 解题思路
主要是利用set容器，耗时较长
执行用时 :748 ms, 在所有 C++ 提交中击败了6.17%的用户
内存消耗 :181.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        multiset<int> arr;
        for(int i = 0; i < nums.size(); i++){
            arr.insert(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];
            multiset<int>::iterator pos = arr.find(target - temp);
            if(pos != arr.end()){
                result.push_back(temp);
                result.push_back(*pos);
                break;
            }
        }
        return result;
    }
};
```