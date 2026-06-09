### 解题思路
![D7M4F_M3)0G0@\[@9\]OC\[JCT.png](https://pic.leetcode-cn.com/968851762028aabc69d383d6077993fb1008edc763d88f54a10c43a0d24e81f5-D7M4F_M3\)0G0@%5B@9%5DOC%5BJCT.png)
首先遍历字符串，两字符串比较，如果上次相等，那这个位置就不用交换，统计不相等位置的x和y的个数
我们来试想下，x+y的得和一定是个偶数，且必须满足统计同偶，才有可能相等，举个例子
xxy
yyx
这种情况下，不管怎么交换，都不可能相等。
第一种情况，奇数
xy
yx
第二种情况，偶数
xyxy
yxyx
这也只需要两次，
也就是每存在偶数个这个除2就可以，如果是奇数的话，加上，第一种情况的两个就可以


### 代码

```cpp
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x=0,y=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==s2[i])
                continue;
            else if(s1[i]=='x')
                x++;
            else
                y++;
        }
        if(x%2==0&&y%2==0)
            return (x+y)/2;
        else if(x%2==1&&y%2==1)
            return (x-1+y-1)/2+2;
        else
            return -1;
    }
};
```