### 解题思路
按照题目的要求去计算，无论怎样迭代，之间一定会有某次是个位数的情况。
个位数里面只有1和7满足条件，其他的都会陷入无限循环，所以迭代到个位数时，只要开是不是7和1的情况即可

### 代码

```cpp
class Solution {
public:
    bool isHappy(int n) {
        int c=INT_MAX;
        while(c>=10)
        {
            c=0;
            
            while(n>0)
            {
                c=c+(n%10)*(n%10);
                n=n/10;
            }
            n=c;cout<<c<<endl;
        }
        if(c==7||c==1)
        return true;
        return false;
    }
};
```