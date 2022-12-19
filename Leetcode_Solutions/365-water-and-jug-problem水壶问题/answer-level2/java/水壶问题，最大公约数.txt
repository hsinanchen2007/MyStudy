### 解题思路


### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        int temp;
        if(z==0||x+y==z)
            return true;
        if(z>x+y)
            return false;
        if(x>y)
            {temp=x;x=y;y=temp;}
        if(x==0)
            {return y==z;}
        int n=x;
        while(y%x!=0)
        {n=y%x;y=x;x=n;}
        return z%n==0;

    }
}
```