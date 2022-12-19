滑铁卢。

费死劲了也没写对，抄答案都抄不对，死活没想到k=1的时候直接返回0就行。

思路很清晰，如果当前乘积小于k，那么right左边含right的所有子串乘积一定都小于k；如果新来个right后乘积大于等于k了，那么就缩left，直到乘积再次小于right，此时left与right之间所有含right的子串的乘积一定都小于k。

边界条件啊边界条件，到底啥时候终止怎么死活想不对呢。

### 代码

```cpp []
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0;
        int product = 1;
        int left = 0, right = 0;
        while(right < nums.size()){
            product *= nums[right];
            while(product >= k){
                product = product / nums[left];
                left ++;
            }
            ans += right-left+1;
            right ++;
        }
        return ans;
    }
};

```
```cpp []
//没想到k=1时也能直接返回，导致后面需要多一步判断
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int N = nums.size();
        int ans = 0;
        int product = 1;
        for(int left = 0, right = 0;right <N;right++){
            product *= nums[right];
            while(product >= k && left <= right){//由于要考虑k=1的情况，这里必须要防止left超过right
                product /= nums[left];
                left ++;
            }
            ans += right - left + 1;
        }
    return ans;
    }
};
```