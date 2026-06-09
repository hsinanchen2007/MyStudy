### 解题思路
通过对数组执行一次异或运算，得到的结果temp是两个不同数字a、b异或的结果。然后temp二进制上第一个非零位置就是a、b两个数字第一个不同的二级制位，记为pos。我们可以根据pos位上是0或者是1将数组分成两部分，每部分都是一个出现一次的数字和0~n个出现两次的数字，执行一次异或运算即可得到出现一次的数字。
### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 位运算。将数组分为两个部分。每一部分只含有一个出现一次的数字，其余部分为重复数字。
        // 问题转化为在一个只有一个数字出现一次，其余数字都出现两次，寻找该数字的问题。
        // 对进行一遍异或运算。根据结果中出现1的位置，可以将数组分为两部分
        int len = nums.size();
        vector<int> res(2);
        fill(res.begin(),res.end(),0);
        
        int temp = 0; // 用于对nums数组进行一遍异或运算
        for(int i=0;i<len;i++){
            temp = temp^nums[i];
        }
        // 寻找temp二进制第一个为1的位置
        int pos = 0; //记录要右移的位数
        while((temp&1)!=1){
            pos++;
            temp = temp>>1;
        }
        // cout<<pos<<endl;
        //根据该pos位置将nums分为两部分，直接进行位运算
        for(int i=0;i<len;i++){
            if((nums[i]>>pos)&1==1){
                res[0] = res[0]^nums[i];
            }
            else res[1] = res[1]^nums[i];
        }
        return res;
    }
};
```