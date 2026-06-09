### 解题思路
##### 异或的性质：
    1.两数异或，相同为0，不同为1；
    2.任意数与0异或为其自身

1.现已知该数组中只有两个不同元素。故假设a,b为数组中的唯二的两个不同值。初始化tmp = 0 来记录（为什么初始化tmp = 0，这是因为：异或的性质2），对整个数组异或一遍，tmp最终肯定得到非零数，否则a,b就为相同数；（此时tmp = a ^ b）

2.然后利用该非零数tmp的二进制表示（"xxxxx...1...xxxx"）知一定存在某位为 1 ;（由  异或  的性质可知，a,b在该**位置**上一定是：a为0，b为1（或者a为1，b为0））；

3.对数组按照该位置进行**分别异或**运算（即**分成两份**，a在其中一份，b在另一份），可以得到a和b;(a = left,b = a ^ a ^ b = a ^ tmp ,所以利用tmp可以省去一个变量来存储b)

### 代码

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int i,tmp = 0,k,left = 0;
        
        for(i = 0;i < nums.size();i++) tmp ^= nums[i];

        k = tmp & (-tmp);   //求tmp二进制表示的最后一位1

        for(i = 0;i < nums.size();i++)
            if(nums[i] & k) left ^= nums[i];
        
        return vector<int>{left,tmp^left};
    }
};
```