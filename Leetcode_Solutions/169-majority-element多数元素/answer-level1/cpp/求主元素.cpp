### 解题思路
初始化第一个元素为主元素，且初始化计数为1
从第二个元素开始遍历一遍数组，若该元素和主元素相等则计数count加一，否则计数减一
若计数减为零，则将该元素记为主元素，继续遍历
结束遍历，即求得主元素

原理：因为主元素的个数超过 ⌊ n/2 ⌋，当遍历一遍数组时，遇到不同的个数少于一半，遇到相同的个数多于一半，即加一的次数多于减一的次数，最终count的计数将不会降为零，即求得主元素。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majElement = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (majElement == nums[i]) ++count;
            if (majElement != nums[i]) --count;
            if (!count) {
                majElement = nums[i];
                ++count;
            }

        }
        return majElement;
    }
};
```