## 暴力枚举
### 解题思路
枚举每个士兵，判断是否满足题意。满足题意的就使答案加1.

### 代码
```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ret = 0;
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++) 
                for (int k = j + 1; k < n; k++) 
                    if (rating[i] < rating[j] && rating[j] < rating[k]) 
                        ret++;
                    else if (rating[i] > rating[j] && rating[j] > rating[k]) 
                        ret++;
        return ret;
    }
};
```

## 数学
### 解题思路
数学方法关键是枚举的对象。
枚举每一个士兵j为中间的情况：
* 设士兵j左边的比rating[j]小的个数为`left_small`, 比rating[i]大的个数为`left_big`; 同理，右边比其小的个数为`right_small`， 比其大的个数`right_big`
* 以该士兵为中间的可能情况的个数为`left_small * right_big + left_big * right_small`。 枚举每个士兵的可能情况总和即为答案

分析为什么`left_small * right_big + left_big * right_small`是答案：
对于每个士兵j作为中间
要使 rating[i] < rating[j] < rating[k] 左边i有`left_small`种选择， 右边比j大的k有`right_big`种选择。
同理， 要使 rating[i] > rating[j] > rating[k] 左边i有`left_big`种选择， 右边比j大的k有`right_small`种选择。

### 代码

```cpp
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;
        int ret = 0;
        for (int j = 0; j < n; j++) {
            int left_small = 0, left_big = 0;
            int right_small = 0, right_big = 0;
            for (int i = 0; i < j; i++) {
                if (rating[j] > rating[i]) left_small++;
                else if (rating[j] < rating[i]) left_big++;
            }
            for (int k = j + 1; k < n; k++) {
                if (rating[j] > rating[k]) right_small++;
                else if (rating[j] < rating[k]) right_big++;
            }
            ret += left_small * right_big + left_big * right_small;
        }
        return ret;
    }
};
```