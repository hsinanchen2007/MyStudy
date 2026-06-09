### 解题思路
核心思路：求x和y的最大公因子t，判断z能否整除t
注意特例：
1、两个水壶容量之和要不小于目标水量，否则两个水壶当然得不到规定要求的水量；
2、目标水量为0，恒为成功；
3、某个水壶容量为0，那么若：另一壶容量==目标水量->true，否则为false。
### 代码

```cpp
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z){
            return false;
        }
        if(z==0)return true;
        if(x==0){
            if(y==z)return true;
            else return false;
        }
        if(y==0){
            if(x==z)return true;
            else return false;
        }
        if(x==y){
            if(z==0||x==z)return true;
            else return false;
        }
        while((x-y)!=0){
            if(x>y)x=x-y;
            else y=y-x;
        }
        //得到x=y即为原来x，y的最大公因子
        if(z%x==0){
            return true;
        }
        else{
            return false;
        }
    }
};
```