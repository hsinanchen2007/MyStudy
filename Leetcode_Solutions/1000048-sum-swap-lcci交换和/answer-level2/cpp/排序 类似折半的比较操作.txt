### 解题思路
1. 由于需交换元素，需求得剩余元素和，故首先求出两个数组的各自总和sum1, sum2
2. 根据等式sum1 - array1[i] + array2[j] == sum2 - array2[j] + array1[i]，
   变换后得到， sum1 + 2 * array2[j] == sum2 + 2 * array1[i]
遍历整个array1,array2数组，确定i，j位置，测试用例会导致超时
3. 于是想到对array1, array2排序，在根据等式大小的比较结果，调整array1或array2的索引，类似折半的比较操作

### 代码

```cpp
class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int sum1 = 0, sum2 = 0;
        for (auto n : array1) {
            sum1 += n;
        }
        for (auto n : array2) {
            sum2 += n;
        }
        vector<int> res;
        sort(array1.begin(), array1.end());
        sort(array2.begin(), array2.end());
        int i = 0, j = 0;
        while (i < array1.size() && j < array2.size()) {
            // sum1 - array1[i] + array2[j] == sum2 - array2[j] + array1[i]
            int val1 = sum1 + 2 * array2[j];
            int val2 = sum2 + 2 * array1[i];
            if (val1 > val2) {
                // 说明交换的元素array1[i]小了，导致val2比较小，所以递增i
                ++i;
            } else if (val1 < val2) {
                // 说明交换的元素array2[j]小了，导致val1比较小，所以递增j
                ++j;
            } else {
                res.insert(res.begin(), {array1[i], array2[j]});
                return res;
            }
        }
        return res;
    }
};
```