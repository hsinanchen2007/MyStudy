    
将两个单次(奇数次)数的划分到两个不同子数组  再使用按位异或分别求出两个子数组中的单次(奇数次)数

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        vector<int> v(2);
        
        int xor_result = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            xor_result ^= nums.at(i);
        }

        int separator = xor_result & (-xor_result); //以separator的二进制表示的位 划分两个单次(奇数次)数的到不同数组

        for (int i = 0; i < nums.size(); ++i)
        {
            if ((nums.at(i) & separator) == 0) //在separator的二进制表示的位上为0
            {
                v.at(0) ^= nums.at(i);
            }
            else //在separator的二进制表示的位上为1
            {
                v.at(1) ^= nums.at(i);
            }
        }

        return v;
    }
};