### 解题思路
1.首先当k为一般值时，通用的解法是进行三次旋转
原始数组[1 2 3 4 5 6 7]
头到尾的第一次旋转[7 6 5 4 3 2 1]
头到第k个数的第二次旋转[5 6 7 4 3 2 1]
第k+1个数到尾的第三次旋转[5 6 7 1 2 3 4]
可以看到当k不为特殊边界值的时候，按照此方法一定可以得出答案。
2.考虑边界值
所谓边界值，即当k恰好为0或者恰好与数组长度相等的情况。
k为0显然不做处理，而当k恰好与数组长度相等时，也无需做任何处理
例：原始数组[1 2 3]
k=1 数组[3 1 2]
k=2 数组[2 3 1]
k=3 数组[1 2 3]
容易看出，当k=6或k=9时，仍等同于k=3的情况。
由此总结出一般规律，对于长度为n的数组，当k是n的整数倍时（即k%n==0）均无需做任何处理。



### 代码

```cpp
class Solution {
public:
    void reverse(vector<int>& nums,int begin,int end)
    {
        while(begin<end)
        {
            int temp=nums[begin];
            nums[begin++]=nums[end];
            nums[end--]=temp;

        }
    }
    void rotate(vector<int>& nums, int k) {
        if(k<=0||k%nums.size()==0)
        return;
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,(k-1)%nums.size());
        reverse(nums,k%nums.size(),nums.size()-1);
    }
};
```