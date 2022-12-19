## 思路一：基于有序set
利用set有序特性。然后从头开始遍历，寻找最大连续子序列。
**注意：set插入时间复杂度：O(logn)**

### 代码
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {                
        int res = 0;     
        set<int> numSet;
        for (int num : nums) {
            numSet.insert(num);
        }   
        set<int>::iterator it;        
        for (it = numSet.begin(); it != numSet.end();) {
            int c = 1;
            int tmp = *it;
            while (++it != numSet.end() && *it - tmp == 1) {
                ++c;
                tmp = *it;                
            }
            res = max(res, c);            
        }
        return res;
    }
};
```

## 思路二：基于无序set
**注意：unordered_set插入时间复杂度：O(1)**

### 代码
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {        
        int res = 0;     
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int n : nums) {
            if (!numSet.count(n)) continue;
            numSet.erase(n);
            int pre = n - 1, next = n + 1;
            while (numSet.count(pre)) numSet.erase(pre--);
            while (numSet.count(next)) numSet.erase(next++);
            res = max(res, next - pre - 1);
        }          
        return res;
    }
};
```


