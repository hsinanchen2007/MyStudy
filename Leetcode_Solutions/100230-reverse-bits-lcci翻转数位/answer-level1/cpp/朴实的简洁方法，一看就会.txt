### 解题思路
菜鸡并不会动态规划，所以用的笨办法
首先我们设立三个指针位，指向这个二进制串中三个相邻的0（就是挨得最近的三个，比如11***0***11***0**1111***0** ），那么翻转后连续1的长度就是（第一指针-第三指针-1）
边界情况就是
1. 起始状态把三个指针指向-1，
2. 遍历二进制串到第32位后仍然要更新一次：第三指针和中间指针分别更新后将第一指针指向第33位（数字上就是32）。

判断某位为0还是1我用了bitset，也可以自行判断
![1.png](https://pic.leetcode-cn.com/7c475f75ee0467f7a1089666c551d19ee114d28b4457503ad349f98fccd7da75-1.png)

### 代码

```cpp
class Solution {
public:
    int reverseBits(int num) {
        bitset<32> store(num);
        int res =  0;
        int fir = -1 , mid = -1 , temp = -1;//三个指针
        for(int i = 0 ; i <= 32 ; i++){
            if(i==32||!store.test(i)){
                fir = mid;
                mid = temp;
                temp = i;
                res = max(temp-fir-1,res);
                
            }
        }
        
        return res;
    }
};
```