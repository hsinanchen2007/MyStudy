### 解题思路
这题我用**位运算**来实现。

对于数组nums中的每一个数，我都用一个bit位来标记。
（1）遍历开始之前，所有数字的bit位都置为0；
（2）对于当前数字nums[i],先调用isBitZero判断nums[i]对应的bit位是否为0；
（3）nums[i]对应的bit位为0：表示nums[i]尚未出现过，那么i对应的bit位置为1；
（4）nums[i]对应的bit位为1：表示此前nums[i]已经出现过，此时中止遍历，返回nums[i].

**关键点1：怎么判断nums[i]对应的bit位是否为0？**
假设用flag来保存所有标记, 判断 flag & (1<<nums[i])是否为0就可以了。

**关键点2：怎么将nums[i]对应的bit位置为1？**
假设用flag来保存所有标记，运算 flag | (1<<nums[i]) 即可。

**关键点3：用什么来保存这个bit位标记呢？**
用int整型变量是不行的，如果nums[i]超过32，1<<32就会出问题。所以用一个整型数组vector<int>flag.
数组元素个数 = n/32+1, n为nums数组里最大数
nums[i]应该用flag数组里哪个元素来标记？——nums[i]/32
nums[i]应该用flag数组对应元素的哪一位来标记？——nums[i]%32

### 代码

```cpp
class Solution {
public:
    bool isBitZero(vector<int> &flag,int bit){
        int t = 1<<(bit%32);
        int res = flag[bit/32]&t;
        return res == 0;
    }
    void setBit(vector<int> &flag,int bit){
        int t = 1<<(bit%32);
        flag[bit/32] |= t;
    }
    int findDuplicate(vector<int>& nums) {
        int x = nums.size();
        vector<int>flag(x+1,0);
        int res = 0;
        for(int i=0;i<nums.size();i++){
            if(isBitZero(flag, nums[i])){
                setBit(flag,nums[i]);
            }
            else{
                res = nums[i];
                break;
            }
        }
        return res;
    }
};
```