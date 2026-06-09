![image.png](https://pic.leetcode-cn.com/31e600f15af47ef55715189bcfa7120eb86e6a0da8eee1b6482a8c652d1c6b8c-image.png)
 * 注意正负数 * 
刚开始没有考虑正负数问题
写下来全是正数的方法
之后发现正负数，于是分离正负数

#### 过程
1. 新建两个数组neg, pos，将原数组的负数的相反数放入neg中，将原数组的正数放在pos中
2. 排序分离好的数组
3. 设两个下标i = 0, j = 1
4. 如果arr[i] 的两倍 等于 arr[j], 直接返回true
5. 如果arr[i] 的两倍 大于 arr[j], 则向后继续寻找arr[i]的两倍
6. 如果arr[i] 的两倍 小于 arr[j]，则arr[i]的两倍不在数组中，寻找++i，并且如果i要与j向撞也要++j

#### 代码

```cpp
class Solution {
    bool checkIfExistABS(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        if (len >= 2) {
            for (int i = 0, j = 1; j < len; ) {
                int temp = arr[i] * 2;
                if (temp == arr[j])
                    return true;
                if (temp > arr[j]) {
                    ++j;
                } else {
                    if (i + 1 >= j)
                        ++j;
                    ++i;
                }
            }
        }
        return false;
    }
public:
    bool checkIfExist(vector<int>& arr) {
        int len = arr.size();
        vector<int> neg;
        vector<int> pos;
        neg.reserve(len);
        pos.reserve(len);
        for (int i = 0; i < len; ++i) {
            if (arr[i] < 0)
                neg.push_back(-arr[i]);
            else
                pos.push_back(arr[i]);
        }
        return checkIfExistABS(neg) || checkIfExistABS(pos);
    }
};
```

#### 复杂度

时间复杂度 : O(n * log(n))