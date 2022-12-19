### 解题思路

思路：从双指针暴力解到滑窗法求解
1、题目拿到，做先想到的应该是双指针的解法，也就是快慢指针，快指针向前移动直到条件由满足到不满足的情况，中间过程统计次数
2、不满足时将慢指针往前移动1，同时快指针回溯到慢指针位置，说白了就是一种暴力的解法，对这个题目肯定会超时的。

那么可以考虑换种方法
1、题目中要求不同元素个数为K，我们其实可以固定一个含K个不同元素的窗口并且不断往右扩展窗口，hash表维持，当窗口内元素等于K时进行统计，超过K时，从左开始缩小窗口，其实也是含双指针的意思
2、窗口中元素个数满足的状态下进行结果统计，这个结果统计有一定技巧，比如[1 2 2 1]窗口，首先[1 2 2 1]必然会第一个统计，那么[2 2 1]和[2 1]呢，可以通过移动左侧窗口同时保持窗口内含K个元素的特征，进行统计，右边窗口不能移动。
3、需要注意的是，在进行左窗口滑动遍历后，需要进行hash数据的恢复，中间只是用作临时计算改变了hash表中存储的数据值。

152ms 47.3M
--- wangtao HW-2020/3/7

### 代码

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int n = A.size();

        // 表内数字表示当前存储的数字以及个数
        unordered_map<int, int> hash;
        while (right < n) {
            hash[A[right++]]++;

            // 表内超过最大数据时，需要缩小窗口
            while (hash.size() > K) {
                if (hash[A[left]] > 1) {
                    hash[A[left]]--;
                } else {
                    hash.erase(A[left]);
                }
                left++;
            }

            // 表内数据刚好是K时，计算所有结果
            int tmp = left;
            while(hash.size() == K) {
                ans++;
                if (hash[A[tmp]] > 1) {
                    hash[A[tmp]]--;
                } else {
                    hash.erase(A[tmp]);
                }
                tmp++;
            }

            // tmp用作计算，hash中数据需要恢复
            while(tmp > left) {
                hash[A[tmp-1]]++;
                tmp--;
            }
        }
        return ans;
    }
};
```