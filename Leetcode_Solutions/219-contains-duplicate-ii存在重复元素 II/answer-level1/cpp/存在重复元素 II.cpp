### 解题思路
解法一（映射表）：
遍历数组，查看map中是否有与当前元素相等且下标相差k的元素，如果有返回true，否则当前元素及其对应下表值加入map。如果数组遍历完都没有，则返回false。


### 代码

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> myMap;

        for(int i=0; i<nums.size(); i++){
            if(myMap.find(nums[i])!=myMap.end() && i - myMap[nums[i]] <= k){
                return true;
            }else{
                myMap[nums[i]] = i;
            }
        }

        return false;
    }
};
```