### 解题思路
题解传送门：[https://blog.csdn.net/weixin_43787043/article/details/105226674](23)

### 代码

```cpp
#include <algorithm>
#include <climits>
#define MAXN 100000
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 0, dp[MAXN];
        for(int i = 0; i < MAXN; i++)
            dp[i] = 1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) 
                    dp[i] = max(dp[i], dp[j] + 1);
            len = max(len, dp[i]);
        }
        return len;
    }
};
```

```cpp
#include <algorithm>
#include <climits>
#define MAXN 100000
using namespace std;
 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /* 防止nums为空的情况导致RE */
        if(nums.size() == 0)
            return 0;
        int tail[MAXN] = {0}, len = 1; 
        tail[1] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > tail[len])
                tail[++len] = nums[i];
            else {
                int index = Find(tail, 0, len, nums[i]); //二分查找
                tail[index] = nums[i];  //赋值
            }    
        }
        return len;
    }
    /* 在数组a[l..r]中找到 a[k - 1] < temp <= a[k] 
       返回k */
    int Find(int a[], int l, int r, int temp) {
        if(r - l == 1)
            return r;
        int mid = (l + r) / 2;
 
 
        if(temp == a[mid])
            return mid;
        else if(temp < a[mid])
            return Find(a, l, mid, temp);
        else 
            return Find(a, mid, r, temp);    
    }
};
```
