### 解题思路
做完后才知道考虑公约数就完事了，忘得一塌糊涂
![捕获.PNG](https://pic.leetcode-cn.com/ecc28a24e7fc0579dd8b3f936d11cf94cf36d9f1d38fa1f718248249ff6b23c1-%E6%8D%95%E8%8E%B7.PNG)


### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y)return false;
        else if(z==0)return true;
        else if(x==y&&z!=x&&z!=2*x)return false;
        else if((x==0&&y!=0)&&(z!=0||z!=y))||((y==0&&x!=0)&&(z!=0||z!=x)))return false;
        else if((y>x&&y%x==0&&z%x!=0)||(x>y&&x%y==0&&z%y!=0))return false;
        else if((y>x&&y%x!=0&&x!=1&&x%(y%x)==0&&z%(y%x)!=0)||(x>y&&x%y!=0&&y!=1&&y%(x%y)==0&&z%(x%y)!=0))return false;
        else return true;
    }
};
```