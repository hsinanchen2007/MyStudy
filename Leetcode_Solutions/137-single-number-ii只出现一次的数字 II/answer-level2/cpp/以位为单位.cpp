### 解题思路
/*
理解这个题首先要把“数”拆分为“位”
假如一个数x(01011010)出现了3次，那么它的每个位肯定都出现了3次
如果我们能让每个位只要出现三次就自己抵消掉，就能得到只出现一次的各个位
首先是如何找到各个出现3次的位，用one, two, three来表示分别出现1、2、3次的各个位
比如扫描到上面的数x(01011010)，此时one就是(01011010)，two和three是(00000000)
当它出现两次，此时one变为(00000000)(因为各个位都出现了2次)，two变为(01011010)，three仍是全0
当它出现三次，那么one和two都变为(00000000),three此时变为(01011010)
那么我们如何设置，当一个位出现3次就自动归零？
考虑公式：x & ~x = 0， x & ~0 = x
若three某个位为1，那么经过one & ~three和two & ~three后one和two都会变为0
若three某个位为0，那么经过上述步骤one和two的值都不改变
最后返回one
*/
### 代码
```cpp

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one, two, three;
        one  = two = three = 0;
        for(auto num:nums)  {
            two |= (one & num);
            one ^= num;
            three = (one & two);
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};
```