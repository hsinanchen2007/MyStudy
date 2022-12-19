### 解题思路
此处撰写解题思路
思路很简单
1.先把数组排序(如果有一样的就可以把他们搞到一起，便于比较）
2.再使用双指针，访问前后两个元素进行比较，有相同的就return true，一直没有相同的就继续后移比较
### 代码

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 0) {
            return false;
        }
        sort(nums.begin(),nums.end());
        int j = 1;
        for (int i = 0 ; i < nums.size()-1 ; i++) {
            if (nums[i] == nums[j]) {
                return true;
            }
            else {
                j++;
            }
        }
        return false;
    }
};
```