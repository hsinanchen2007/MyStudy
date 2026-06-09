### 解题思路
一开始采用了更慢的方法，时间复杂度需要O(n^2))，因为采用了移动数组元素覆盖重复项，耗时较大，这个弊处也是插入数组的弊处，同样需要移动数组元素。
后来改变思路：只需要遍历整个数组，将不同于“新数组”当前元素即加入“新数组”中，且长度加一，最后返回“新数组”最后一个元素的下标+1，即长度。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newIndex = 0;
        if(nums.size() == 0)
            return 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[newIndex] != nums[i]) {
                newIndex++;
                nums[newIndex] = nums[i];
            }
        }
        return newIndex+1;
    }
};
```