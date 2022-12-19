### 解题思路
注意临界值。

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        if(x==0) return 0;
        long left=1,right=x,pivot;
        
        while(left<right){
            pivot=(left+right)/2;
            if(pivot*pivot<x){
                left = pivot+1;
            }else if(pivot*pivot>x)
                right = pivot-1;
            else
                return (int)pivot;
        }

        return (int)(left*left>x?left-1:left);
    }   
}
```