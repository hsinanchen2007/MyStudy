### 解题思路
**单调栈**
>1.单调递减
>2.存储的每相邻两个数字类似一个区间，
>两数之间较小的数字表示从较小数字到较大数字的区间段的数字都小于等于较小数字

**反观此题**
倒序数组存储一个单调栈，保证如果当前数比栈顶小，那么栈顶一定是当前数所能发现的第一个最大值
**而不是 *栈顶和栈顶的下一元素之间的元素*   或者   *栈顶元素***
### 代码

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n,-1);
        
        stack<int> small;
        int index;
        for(int i=2*n-2;i>=0;i--){
            
            if(i>=n) index=i-n;
            else index=i;
            while(!small.empty()&&small.top()<=nums[index]){
                small.pop();
            }
            if(!small.empty() && i<n) out[index] = small.top();
            small.push(nums[index]);
        }
        
        return out;
    }
};
```