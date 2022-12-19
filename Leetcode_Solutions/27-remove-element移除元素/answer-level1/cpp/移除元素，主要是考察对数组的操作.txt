## 思路 

> 笔者在BAT从事技术研发多年，利用工作之余重刷leetcode，更多原创文章请关注公众号「代码随想录」。
这道题目也是O(n)的解法
建议做完这道题，接着再去做 26. 删除排序数组中的重复项， 对这种类型的题目就有有所感觉

## 解法 

```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (val != nums[i]) {
                nums[index++] = nums[i]; // 注意是index++ 而不是 ++index
            }
        }
        return index;
    }
};
```
