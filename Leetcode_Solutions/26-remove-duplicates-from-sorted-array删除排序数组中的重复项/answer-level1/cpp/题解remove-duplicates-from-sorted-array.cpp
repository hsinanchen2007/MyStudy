### 解题思路
典型双指针，i负责指向存储结果，k负责指向原数组进行遍历。
1、当k指向的元素与i指向的元素相等时，k加1后移一位；
2、当k指向的元素与i指向的元素不等时，即找到数组中的“未重复元素临界点”；
3、将k指向的不等元素i+1指向的元素，即在原地移除了从i+1到k-1指向的所有重复元素；
4、重复以上三步，遍历数组完成后，返回i+1作为结果数组长度即可。

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0;
        for (int k = 1; k < nums.size(); k++) {
            if (nums[i] != nums[k]) {
                i++;
                nums[i] = nums[k];
            }
        }
        return i + 1;
    }
};
```