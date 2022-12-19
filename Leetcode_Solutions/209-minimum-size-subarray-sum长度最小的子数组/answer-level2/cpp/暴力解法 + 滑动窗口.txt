### 解题思路
    打卡学习 ~ ~ ~
### 代码

```cpp
/*暴力做法*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(),minlen = INT_MAX;
        for(int i = 0;i < n;i++){
            int k = i,sum = 0;
            while(k < n){
                sum += nums[k];
                k++;
                if(sum >= s){
                    minlen = min(minlen,k - i);
                    break;
                }
            }
        }
        return minlen != INT_MAX ? minlen : 0;
    }
};

/*双指针：滑动窗口*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(),l = 0,r = 0,sum = 0,minlen = INT_MAX;
        if(n == 0) return 0;
        while(r < n){
            sum += nums[r];
            r++;
            while(sum >= s){
                minlen = min(minlen,r - l);
                sum -= nums[l];
                l++;
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
```