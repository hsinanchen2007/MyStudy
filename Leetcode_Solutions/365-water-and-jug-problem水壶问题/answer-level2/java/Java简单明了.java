### 解题思路
大事化小小事化了

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z>x+y||z<0){
            return false;
        }
        if(y%2==0&&x%2==0&&z%2!=0){
            return false;
        }
        if(x==z||y==z||z==x+y||z==0){
            return true;
        }
        while(x>0&&y>0){
            int temp=x;
            x=x>y?y:x;
            y=temp>y?temp:y;
            z=z>y?z-y:z;
            y-=x;
            if(x==z){
                return true;
            }
        }
        return false;

    }
}
```