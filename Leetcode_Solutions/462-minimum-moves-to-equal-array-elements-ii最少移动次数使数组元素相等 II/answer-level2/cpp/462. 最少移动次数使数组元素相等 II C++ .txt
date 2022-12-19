### 解题思路
中位数是最优解：关键要理解这个
以如下例子说明：
1,2,3,7,10；

假设我们选择第2个元素：
1）对于1和10而言，nums[1]-nums[0]+nums[4]- nums[1] = nums[4]-nums[0];
这说明，在1~10之间，选择任何一个元素，对于1和10都是最少移动次数
2）对于3和7而言，nums[2]-nums[1] +nums[3] -nums[1] 要大于2~7的差值；

因此，有一个很重要的结论：**在两个边界范围内，选择任意元素向他靠近移动的次数是相同的。**
a,b,c,d,e,f：
对于a,f来说，选择b,c,d,e做移动都一样，移动次数都等于 f-a；
对于b,e来说，选择c,d做移动都一样，移动次数都等于e-b；**如果选择其他字符，就会超过e-b**
对于c,d来说，选择中间的任何数做移动都一样，移动次数都等于d-c；**如果选择其他字符，就会超过d-c**

因此，我们选择中位数，做差值求和



### 代码

```cpp
class Solution {
public:
    int minMoves2(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int result = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() % 2 == 0) {
            left = nums.size() / 2 - 1;
            right = nums.size() / 2;
        } else {
            left = nums.size() / 2 - 1;
            right = nums.size() / 2 + 1;
        }

        while (left >= 0 && right < nums.size()) {
            result += nums[right] - nums[left];
            left--;
            right++;
        }

        return result;
    }
};
```