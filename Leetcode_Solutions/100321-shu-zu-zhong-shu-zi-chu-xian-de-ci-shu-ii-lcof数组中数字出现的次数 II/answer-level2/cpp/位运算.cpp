### 解题思路
考虑二进制形式。以第一个二进制位为例，[1,2,2,2] 四个数字的二进制位的第一位均为1，和为4。4%3即为扣除掉出现三次的数字后，只出现一次的数字的个位，其余各位置同理。
### 代码

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 统计二进制各位的和，每位对3求余
        int ans = 0;
        for(int i=0;i<32;i++){
            //统计三十二位各个位置上的值
            int count = 0; //统计i位置上的和
            for(auto c:nums){
                if((c>>i)&1) count++; 
            }
            ans += (count%3)<<i;
        }
        return ans;
    }
};
```