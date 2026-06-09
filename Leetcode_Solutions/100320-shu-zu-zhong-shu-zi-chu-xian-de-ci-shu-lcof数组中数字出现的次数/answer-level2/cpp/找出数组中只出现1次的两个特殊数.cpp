### 解题思路
首先是解题思路：利用异或运算，异或的特点是相同的数异或为0,任何数与0异或仍为其本身
首先想办法将两个数分离，由于两个数只出现一次，所以肯定不一样，即有一位不相同，所以可以把原数组分为2个数组
一个数组是该位为1，一个数组为该位为2，然后再分别对这两个数组异或，结果就是a和b
代码上的问题= =（超坑）  首先由于0异或的特殊性，所以可以将a\b等初始值设为0，其次注意(nums[i] & one_bit) == 0
由于==比&有更高的运算优先级，所以还得小心= =  然后就是唯一运算，别忘了加=，光有one_bit<<1根本不会对one_bit产生更改

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        if(nums.empty())
            return {};
        int all_nums(nums[0]);
        int a(0),b(0);
        int one_bit = 1;
        for (int i=1;i<nums.size();i++){
            all_nums ^= nums[i];
        }

        while(!(one_bit & all_nums)){
            one_bit <<= 1;
        }

        for(int i=0;i<nums.size();i++){
            if((nums[i] & one_bit) == 0 ){
                a ^= nums[i];
            }
            else
                b ^= nums[i];
        }
        return {a,b};
    }
};
```