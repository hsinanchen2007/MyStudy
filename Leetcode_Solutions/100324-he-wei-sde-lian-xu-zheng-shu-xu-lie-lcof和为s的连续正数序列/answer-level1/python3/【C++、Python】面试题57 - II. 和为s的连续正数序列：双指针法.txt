### 双指针法 ###
#### 代码 ####
```cpp []
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int left = 1, right = 1, curSum = 0;
        while (left <= target / 2) {
            if (curSum < target)
                curSum += right++;
            else {
                if (curSum == target) {
                    vector<int> tmp;
                    for (int i = left; i < right; ++i) 
                        tmp.push_back(i);
                    res.push_back(tmp); 
                }
                curSum -= left++;
            }
        }
        return res;
    }
};
```
```python []
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        left = right = 1
        curSum = 0
        while left < target / 2:
            curSum += right
            while curSum > target:
                curSum -= left
                left += 1
            if curSum == target:
                res.append(tuple(range(left, right + 1)))
            right += 1
        return res
```
#### 复杂度分析 ####
- 时间复杂度 $O(n)$，需要循环 $\frac{target}{2}$ 次
- 空间复杂度 $O(1)$，除去保存结果的开销之外不使用额外空间