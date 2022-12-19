### 解题思路
此处撰写解题思路
->->-> 守擂法
当前擂主赢了几次？count为次数
输一次count--，count<0了就换擂主，当前赢的就是擂主。
因为题中约束了一定是存在超过n/2的元素的，所以剩下的一定是这个元素。

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count=1, res=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==res) count++;
            else{
                count --;
                if(count<0){
                    res = nums[i];
                    count = 1;
                }
            }
        }
        if(count>0) return res;
        else return 0;
    }
};
```