将其异或后判断异或后的数中的1的数目

### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        
        int z=x^y;
        int count=0;
        while(z!=0)
        {
            
            if((z&1)==1)
            {
            count++;
            }
             z=z>>1;
       
        }
        return count;
    }
}
```