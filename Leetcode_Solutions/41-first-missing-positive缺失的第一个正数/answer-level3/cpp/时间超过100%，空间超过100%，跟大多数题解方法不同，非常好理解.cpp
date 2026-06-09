1. 先把所有小于等于0的数去掉，只留下大于0的数
2. 然后遍历，并巧妙的留下数字被遍历过的证据
3. 如果num[i]<0，说明i+1出现过，若num[i]>0，说明i+1未出现
4. 如果1到n都出现过，则返回n+1
```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, j = 0;
        //先把所有小于等于0的数去掉，只留下大于0的数
        while (j < nums.size()) {
            if (nums[j] > 0) {
                nums[i++] = nums[j++];
            }
            else {
                j++;
            }
        }
        int n = i;
        //然后遍历，并巧妙的留下数字被遍历过的证据
        for (int i = 0; i < n; i++) {
            int cur = abs(nums[i]);
            if (1 <= cur && cur <= n) {
                nums[cur-1] = -1 * abs(nums[cur-1]);
            }
        }
        //如果num[i]<0，说明i+1出现过，若num[i]>0，说明i+1未出现
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i+1;
            }
        }
        //如果1到n都出现过，则返回n+1
        return n+1;
    }
};
```
