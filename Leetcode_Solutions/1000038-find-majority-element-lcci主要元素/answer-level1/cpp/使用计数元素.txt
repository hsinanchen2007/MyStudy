### 解题思路
从头遍历，设置计数元素k，若遇到非主要元素则-1，遇到主要元素+1，则最后k一定大于0
按照这种思路，假定nums[0]为主要元素，接下来的元素若和假定主要元素相同，则k++，若不同，则k--
若k小于0，则将下一个元素假定为新的主要元素，直到遍历结束。
最后重新验证一遍，若k大于0，则主要元素正确

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k=0;
        int num=nums[0];
        for (int i=0;i<n;i++){
             if (nums[i]==num){
                 k++;
             }
             else {
                 k--;
                 if(k<0){
                     num=nums[i];
                     k=1;
                 }
             }
        }
        int p=0;
        for (int i=0;i<n;i++){
            if(num==nums[i]){
               p++;
            }
            else p--;
        }
        if (p>0){
            return num;
        }
        else return -1;
    }
};
```