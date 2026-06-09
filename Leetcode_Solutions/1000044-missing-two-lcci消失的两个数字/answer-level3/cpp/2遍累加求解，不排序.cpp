### 解题思路和步骤
1. 从1到N数组nums中，缺失了2个元素。那么`N = nums.size() + 2`
2. 缺失2个数字的和`sumOfTwo = sum(1..N) - sum(nums)`
3. 记`threshold = sumOfTwo/2`。因为缺失的2个数字不相等，所以一个小于等于threshold,一个大于threshold。
4. 只对小于等于threshold的元素求和，得到第一个缺失的数字:
    `sum(1..threshold) - sum(nums中, 小于等于threshold的元素)`
6. 第二个缺失的数字: `sumOfTwo - 第一个缺失的数字`  
  
### 复杂度分析    
时间复杂度：O(n)
空间复杂度：O(1)

```c++
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int sum = 0;
        for (auto e : nums) {  // 所有元素求和
            sum += e;
        }

        int nr = nums.size() + 2;
        int sumOfTwo = (1+nr)*nr/2 - sum;  // 计算两个缺失元素和：sum(1..N) - sum(nums)
        int threshold = (sumOfTwo) / 2;

        sum = 0;
        for (auto e : nums) {
            if (e <= threshold) {  // 小于等于threshold的元素求和
                sum += e;
            }
        }

        vector<int> res;
        res.push_back((1+threshold)*(threshold)/2 - sum); // 第一个缺失的数字：sum(1..threshold) - sum(nums中小于等于threshold的元素)
        res.push_back(sumOfTwo-res[0]);   // 相减直接得到 第二个缺失的数字

        return res;
    }
};
```


