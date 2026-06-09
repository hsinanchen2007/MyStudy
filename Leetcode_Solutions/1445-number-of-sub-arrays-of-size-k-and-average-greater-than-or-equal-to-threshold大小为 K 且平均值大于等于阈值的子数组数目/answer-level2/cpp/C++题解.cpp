### [1343. 大小为 K 且平均值大于等于阈值的子数组数目](https://leetcode-cn.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/submissions/)

#### 题解
   + 先统计前k个数组元素之和
   + 利用滑动窗口思想，向后滑动，减去第一个元素，加上后一个元素得到下一个子数组的和
   + 判断sum是否满足题目要求
   + 更多题解: [>>请点击<<](https://tawn0000.github.io/2020/02/08/leetcode-week-contest/)

#### 代码
```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, res = 0;
        for(int i = 0; i < k; i++)
            sum += arr[i];
        if(sum >= threshold*k) res ++;
        for(int i = k; i < arr.size(); i++)
            {
                sum += (arr[i]-arr[i-k]);
                if(sum >= threshold*k) res ++;
            }
        return res;
    }
};
```
