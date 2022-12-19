## 直观思路
最直观想到的方法是暴力方法
```C++ []
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum = 0, limit = (target - 1) / 2; // (target - 1) / 2 等效于 target / 2 下取整
        for (int i = 1; i <= limit; ++i) {
            for (int j = i;; ++j) {
                sum += j;
                if (sum > target) {
                    sum = 0;
                    break;
                }
                else if (sum == target) {
                    res.clear();
                    for (int k = i; k <= j; ++k) res.emplace_back(k);
                    vec.emplace_back(res);
                    sum = 0;
                    break;
                }
            }
        }
        return vec;
    }
};
```
## 双指针法
左指针记录开始点，右指针记录结束点。
``` C++ []
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1;
        int right = 2;
        vector<vector<int>> ans;
        vector<int> res;
        while (left < right){
            int sum = (left + right)*(right - left + 1)/2;
            if (sum < target) right++;
            else if (sum > target) left++;
            else{
                res.clear();
                for (int k = left; k <= right; ++k) res.emplace_back(k);
                ans.emplace_back(res);
                left++;
                right++;
            }       
        }
        return ans;
    }
};
```
```python []
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        left, right =1, 2
        ans = []    
        while left < right:
            res = []
            sum = (left + right)*(right - left + 1)/2 ##等差数列求和
            if sum > target:
                left += 1
            elif sum < target:
                right += 1
            else:
                for i in range(left, right + 1):
                    res.append(i)
                ans.append(res)
                left += 1
                right += 1
        return ans
```