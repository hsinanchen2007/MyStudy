### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int my_gcd(int& a,int& b){
        while(a!=0&&b!=0){
            a%=b;
            if(a==0){
                break;
            }
            swap(a,b);
        }
        return b;
    }

    bool canMeasureWater(int x, int y, int z) {
        //辗转相除法求最大公约数
        if(x==0){
            return z==x||x+y==z;
        }
        else if(y==0){
            return z==y||x+y==z;
        }
        else if(x+y<z){
            return false;
        }
        return z%(my_gcd(x,y))==0;
    }
};
```