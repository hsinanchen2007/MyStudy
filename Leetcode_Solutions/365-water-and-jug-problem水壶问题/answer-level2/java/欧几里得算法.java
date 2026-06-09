### 解题思路
解题难点：1.倒水问题是否可以转换成最大公因数问题？（通过过程模拟，答案是可以的）
2.如何找到最大公因数：欧几里得算法
### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        /*把该死的0拒之门外*/
        if (( x==0||y==0)&&(x!=z&&y!=z) ){
            return false;
        }
        if (z==0){
            return true;
        }

        int big =  Math.max(x,y);
        int small = Math.min(x,y);
        /*直接等的情况*/
        if (x==z||y==z||z==x+y){
            return true;
        }
        if (x==y){
            return false;
        }
        /*3.越上界的情况*/
           if (z>big+small){
               return  false;
           }
           /*4.越下界的情况,不需要考虑*/
        int difference = gcd(big,small) ;
            /*5.z介于x+y和0之间,需要构造的情况*/
        if (difference==0){
            return false;
        }
             return z%difference==0?true:false;
    }

    int gcd(int m,int n)
    {   if(n == 0){
        return m;
    }
        int r = m%n;
        return gcd(n,r);
    }
}


```