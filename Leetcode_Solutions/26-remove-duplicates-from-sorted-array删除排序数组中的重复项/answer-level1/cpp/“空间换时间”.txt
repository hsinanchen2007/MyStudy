### 解题思路
我的想法是空间换时间，空间采用的是哈希表，这种方法不大好，不能说是O(1)空间复杂度。执行nums.erase(it)这句的时候it会变成野指针，需要重新定位。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> mymap;
        vector<int>::iterator it = nums.begin();
        // int size = nums.size();
        for(int i = 0; it != nums.end(); ){
            if(!mymap.insert(pair<int, int>(nums[i], 1)).second){
                nums.erase(it); //it失效
                it = nums.begin() + i;
            }
            else{
                ++i;
                ++it;
            }
        }
        return nums.size();
    }
};
```