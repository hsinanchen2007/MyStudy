### 思路一：set
1. 利用set去重和排序（从小到大）
2. 反向遍历，

### 代码
时间复杂度：O(nlogn)
```cpp
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (const auto &n : nums) {
            st.insert(n);
        }
        auto it = st.crbegin();
        int i = 0;
        while (i < 2 && it != st.crend()) {
            ++i;
            ++it;            
        }
        return it != st.crend() ? *it : *st.crbegin();
    }
};
```
### 另一种写法
```c++
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for (const auto &n : nums) {
            st.insert(n);
            if (st.size() > 3) {
                st.erase(st.begin());
            }
        }
        return st.size() == 3 ? *st.begin() : *st.rbegin();//返回最大数，st.end()表示最大数后面的数
    }
};
```

### 思路二：设置变量
设置三个变量表示前三大的数，不断更新值。

### 代码
时间复杂度：O(n)
```c++
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for (const auto &n : nums) {
            if (n > first) {
                third = second;
                second = first;
                first = n;
            } else if (n > second && n < first) {
                third = second;
                second = n;
            } else if (n > third && n < second) {
                third = n;
            }
        }
        return third == LONG_MIN ? first : third;
    }
};
```

