### 解题思路
遍历数组，对于nums[i]，二分找到序列中第一个大于等于nums[i]的位置
将nums[i]替换temp[i]或者插到temp数组的末尾

举例：
给定nums = [1, 2, 3, 10, 3, 4, 5]
初始temp = []

第一趟结束: temps = [1]

第二趟结束: temps = [1, 2]

第三趟结束: temps = [1, 2, 3]

第四趟结束: temps = [1, 2, 3, 10]

第五趟结束: temps = [1, 2, 3, 10]   此时已经用nums[4]上的3代替了nums[2]上的3，第一个大于等于的位置

第六趟结束: temps = [1, 2, 3, 4]    此时用4代替10

第七趟结束: temps = [1, 2, 3, 4, 5]

这里采用二分方式查找temps数组中第一个大于等于欲插入数字的位置(若新数字最大，位置会自动排在最后面)
这里我将temps数组的第一个数字放在temps[1]位置，这样的话二分比较好写

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int *temp = new int[(int)nums.size() + 1]();
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int pos = bin_search(nums[i], 1, ans, temp);
            temp[pos] = nums[i];
            ans = max(ans, pos);
        }
        return ans;
    }
    int bin_search(int res, int l, int r, int temp[]) {
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(res == temp[mid]) return mid;    // 特判相等情况
            if(res > temp[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
```