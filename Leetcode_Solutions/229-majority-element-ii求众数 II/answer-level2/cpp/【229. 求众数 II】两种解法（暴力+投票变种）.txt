## 思路一：暴力
### 代码
```c++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        if (size == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());        
        int c = 1, m = nums[0];        
        for (int i = 1; i < size; ++i) {
            if (nums[i] == m) {
                ++c;                
            } else {
                if (c > (size / 3)) {
                    res.push_back(m);
                } 
                c = 1;
                m = nums[i];
            }
        }
        if (c > (size / 3)) {
            res.push_back(m);
        }
        return res;
    }
};
```

## 思路二：投票加验证
满足条件的数最多为两个，找出两个候选数进行投票，进行两次遍历，第一次遍历找到两个候选数，第二次遍历统计出现次数，最后验证是否满足出现次数。
### 代码
```c++
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;        
        if (size == 0) {
            return res;
        }
        int a = 0, b = 0, cnt1 = 0, cnt2 = 0;//两个候选数为a, b
        for (int num : nums) {
            if (num == a) {
                ++cnt1;
            } else if (num == b) {
                ++cnt2;
            } else if (cnt1 == 0) {
                a =  num;
                ++cnt1;
            } else if (cnt2 == 0) {
                b = num;
                ++cnt2;
            } else {
                --cnt1;
                --cnt2;
            }
        }
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == a) {
                ++cnt1;
            } else if (num == b) {
                ++cnt2;
            }
        }
        if (cnt1 > size / 3) {
            res.push_back(a);
        }
        if (cnt2 > size / 3) {
            res.push_back(b);
        }
        return res;
    }
};
```

