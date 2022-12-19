# 二分nlogn

        既然有序、唯一答案，而且index1小于index2
        扫一遍，二分他右边的  nlogn
        直接用lower_bound省事，当然也可以手写拉

```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> ans;
        int len = numbers.size();
        for (int i = 0; i < len; ++i) {
            int value = target - numbers[i];
            int lc = lower_bound(numbers.begin() + i + 1, numbers.end(), value) - numbers.begin();//从i后面二分找
            if (lc >= len) {
               continue;
            }
            else if (value == numbers[lc]){ //因为函数是找到第一个等于大于的数，所以要确保是否等于
                ans.push_back(i + 1);
                ans.push_back(lc + 1);
                break;
            }
            
        }
        return ans;
    }
};
```

# 双指针

            确保有唯一解，一开始i指最左————A，j指最右—————B
            因为有序，利用起来
            A+B=target
            若A+B大于target   B向左探测 直到小于target停  为什么呢？是否存在B再向左一下才有正确答案
            ***2 5 5 6      设tar=10 可以看出5+5=tar  而2+6确实小于tar，算法停了，下一步5+6>tar 算法停了，5+5
            所以说 这个算法并不会漏掉情况，他是一步步逼近：小了调下A，大了就调下B
            若   小于         A向右探测
            相等 直接存进vector   break
            
            时间复杂度On 比二分优化了一个log
            
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int len = numbers.size();
        for (int i = 0, j = len - 1; i < len; ++i) {
            
            while (numbers[i] + numbers[j] > target)
                j--;
            //此时就是   <= target
            if (numbers[i] + numbers[j] == target) {//若不进就 说明小了 调下A
                ans.push_back(i + 1);//下标从1开始
                ans.push_back(j + 1);
                break;
            }
            
        }
        return ans;
    }
};
```

