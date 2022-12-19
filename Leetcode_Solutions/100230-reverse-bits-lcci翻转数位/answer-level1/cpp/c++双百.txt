### 解题思路
从右往左遍历各个位数的数字，如果是1就加1，并且设置一个bool变量来判断0出现了几次，第一次出现0时，bool变量为true，并设置为false，再记录当前数值，这个数值为下次循环的数值。
![image.png](https://pic.leetcode-cn.com/08bd89f6912b9c9d8fee5e6d97e493cc50113799756b879a258cf1008392e74d-image.png)

### 代码

```cpp
class Solution {
public:
    int reverseBits(int num) {
         if(num==0) return 1;
         int max=0,count=0,pre=num;
         bool b=true;
         while(num)
         {
             count=0;
             b=true;
             while(num)
             {
                if(num&1) 
                {
                   count++;
                   num>>=1;
                }
                else if(b)
                {
                    count++;
                    num>>=1;
                    pre=num;
                    b=false;
                }
                else
                {
                    if(count>max) max=count;
                    num=pre;
                    break;
                }
                if (count+b > max) max = count+b;
             }
         }
         return max;
    }
};
```