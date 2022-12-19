### 解题思路
1. 字符串中一样的我们不用管
2. 不一样的只有两种情况 即:'x'->'y' 和 'y'->'x'两种情况
3. 根据题目中的算例可以发现，x->y 和 x->y交换只用1次  而 x->y 和 y->x交换用两次，所以我们需要尽量让相同状态的去交换
4. 两个status变量记录不一样的状态数量，如果两个数之和为奇数那么返回-1，偶数的话就先让两个状态自己和自己换+1，然后在和对方换+2

### 代码

```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if (s1.size()!=s2.size())
            return -1;
        int sta1=0,sta2=0;
        for (int i=0;i<s1.size();i++){
            if (s1[i]!=s2[i]){
                if (s1[i]=='x') 
                    sta1++;
                else
                    sta2++;
            }
        }
        if ((sta1+sta2)&1==1)
            return -1;
        else
            return sta1/2 + sta2/2 + (sta1%2==0?0:2);
    }
};
```