### 解题思路
1. 比较容易想到的是暴力解法：用变量`ans`存结果，使用指针`left`和`right`完成暴力搜索。初始`left = 0`，`right = left`，`right`指针开始向右移动，扫到一个符合的子数组则`ans++`。直到扫描完`right`指针扫描完数组。`left++`, `right = left`，继续第二轮扫描。直到`left > A.size() - K`，搜索结束。 可以看出`right`指针一直回溯。算法消耗较高。
2. 采用滑动窗口，同样使用`ans`存结果，指针`left`和`right`用来维持窗口大小。具体参考用户[@xiaoneng](/u/xiaoneng/)的[题解](https://leetcode-cn.com/problems/subarrays-with-k-different-integers/solution/chua-dong-chuang-kou-by-xiaoneng/)

### 代码

```cpp
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        if(A.empty()||K==0) return 0;
        int ans = 0;
        int left = 0, right = 0;
        int len = A.size();
        unordered_map<int, int> _map;
        while(right < len){
            _map[A[right++]]++;
            while(_map.size() > K){
                if(_map[A[left]] > 1) _map[A[left]]--;
                else _map.erase(A[left]);
                left ++;
            }
            int temp = left;
            while(_map.size() == K){
                ans ++;
                if(_map[A[temp]] > 1) _map[A[temp]]--;
                else _map.erase(A[temp]);
                temp ++;
            }
            while(temp > left){
                _map[A[temp-1]] ++;
                temp --;
            }
        }
        return ans;
    }
};
```