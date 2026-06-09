### 解题思路

![图片.png](https://pic.leetcode-cn.com/4f94c09a695e4628bbebc0e5606534219249923a725dc9908786506339a347a5-%E5%9B%BE%E7%89%87.png)

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        for(;it < nums.begin()+nums.size();it++)
        {
            if(*it == val)
            {
                nums.erase(it);
                it--;//删除之前的元素，后面的元素会自动补上来，所以要先--，再++
            }
        }
        return nums.size();
    }
};
```