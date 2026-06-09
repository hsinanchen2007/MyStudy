### 解题思路
![image.png](https://pic.leetcode-cn.com/531af0644e6ab8c579a46bb4ce0a4c50cdf4996a75a9d8c3bb5926baeeca3cb8-image.png)
分两个部分：一部分负责判断是否有比当前字典序大的排列，若有就从后面已有的升序排列中找到最小的大于当前值的数字，交换，然后跳出
第二部分，负责没有跳出时(此时后面的数字都比当前的大)，依次交换，使其呈升序排列

一：首先 i 指针从尾端开始向前，然后 j 指针遍历所有 i 指针之后的数字，若该数字大于 i 指针(现在有比目前排列更大的字典序)，就与其做交换。
二：若 j 指针遍历完 i 指针之后的所有数字都没有比 i 指针的数字大的话，就将 i 依次与 j 交换。

这里需要说明的是：当 i = len-2 时，j = len-1，若没有break出来，证明这时候所指的数字小于 i 指针所指的数字，我们交换两个数字，可以使得 i(当前i=len-2) 及 i 以后的数字(len-1处数字)按照升序排列；
下一次，当 i 为小于len-2的某值时(如i=len-3)，若也没有break出来，我们交换 i 处(len-3)与后面数字中最大值(len-1)，然后 i 处数字(当前为原来的len-1处的数字，肯定比len-2大)与len-2处数字交换，这样依次使得 i 以及 i 后面的数字升序排列。
### 代码

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size() <= 1) return ;
        int len = nums.size(),tmp,i = len-2;
        bool flag = false;
        while(i >= 0)
        {
            // 从结尾处开始判断有没有大于当前指针所指数字的值
            for(int j = i+1; j < len; j++)
            {
                if(nums.at(i) < nums.at(j) )
                {
                    tmp = nums.at(i);
                    nums.at(i) = nums.at(j);
                    nums.at(j) = tmp;
                    flag = true;
                    break;
                }
            }
            if(flag) return;
            // 后边的数字都大于当前的，所以和后面的做交换，来使后面的数字按升序排列
            for(int j = len-1; j > i; j--)
            {
                tmp = nums.at(i);
                nums.at(i) = nums.at(j);
                nums.at(j) = tmp;
            }
            i--;
        }
    }
};
```