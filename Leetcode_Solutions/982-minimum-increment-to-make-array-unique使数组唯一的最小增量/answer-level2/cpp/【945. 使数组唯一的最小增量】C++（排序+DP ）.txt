### 解题思路1：先排序 再DP
先用`sort`对数组排序，然后动态规划，依次对A[i]进行调整；
DP过程：遍历A[i]，利用A[i-1]解决A[i];
       1. 当`A[i]<=A[i-1]`时，说明重复或小于前一个数，需要对`A[i]`进行move操作；
       2. 应令`A[i] = A[i-1] + 1`，即在排过序的数组中`A[i]`至少应变为前一个`A[i-1]+1`；
       3. 因此，`A[i]`的移动量为`A[i-1] + 1 - A[i]`
**时间复杂度：** 排序+DP:O(NlogN+N)，即O(NlogN)，N为A的长度
![image.png](https://pic.leetcode-cn.com/8acf0aa5da517196c1e3e684fba02d2e3c1e96b3fc2fd4f7be775a79ed7342bf-image.png)

### 代码

```cpp
class Solution {
    // 先排序，再动态规划；
    // A[i] = A[i-1] + 1，即在排过序的数组中A[i]至少应变为前一个A[i-1]+1；
    // 因此，A[i]的移动量为A[i-1] + 1 - A[i]
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());    // 排序
        int res=0;
        for(int i=1;i<A.size();i++){   //DP 
            if(A[i]<=A[i-1]){
                res+=A[i-1]+1-A[i];   // move
                A[i]+=A[i-1]+1-A[i];    // 更新A[i]
            }
        }
        return res;
    }
};
```
### 解题思路2：计数+遍历所有可能数值
参考 [**官方题解方法一：计数**](https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/solution/shi-shu-zu-wei-yi-de-zui-xiao-zeng-liang-by-leet-2/)
![image.png](https://pic.leetcode-cn.com/8fd3e631045a4e09bc01a9e44672ba305d457014bee321a6553d69538cd57653-image.png)

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int cnt[80000] = {0};   
        for (int a: A) 
            cnt[a]++;
        int res = 0, repeat = 0;  // repeat记录重复个数
        //遍历80000
        for (int a = 0; a < 80000; a++) {
            if (cnt[a] >= 2) {
                repeat += cnt[a] - 1;    // 重复个数+（cnt[a] - 1）
                res -= a * (cnt[a] - 1);  //优化
            }
            else if (repeat > 0 && cnt[a] == 0) {
                repeat--;
                res += a;
            }
        }

        return res;
    }
};
```
