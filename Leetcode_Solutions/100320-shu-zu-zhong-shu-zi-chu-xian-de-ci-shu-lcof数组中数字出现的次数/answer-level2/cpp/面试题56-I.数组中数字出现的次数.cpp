### 解题思路
- 核心要点：巧用位运算异或（^），先计算数组全元素的异或x，利用x&(-x)求出x右边数起第一个1的位置，对应只有这一位为1的数h，然后判断数组元素nums[i]&h的结果，将数组分为两组，分别全异或，得到a和b即为所求
- 执行用时：72 ms, 在所有 C++ 提交中击败了9.50%的用户
- 内存消耗：16.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int a=0, b=0, x=0;
        for(int i=0;i<nums.size();i++){
            x=x^nums[i];
        }
        int h=x&(-x);
        for(int i=0;i<nums.size();i++){
            if((nums[i]&h)==h){
                a=a^nums[i];
            }
            else b=b^nums[i];
        }
        return {a,b};
    }
};
```