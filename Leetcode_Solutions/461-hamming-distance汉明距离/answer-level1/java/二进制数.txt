### 解题思路
这一题要注意循环条件。  while(!(x == 0 && y == 0))


### 代码

```java
class Solution {
    public int hammingDistance(int x, int y) {
        int count = 0;
        while(!(x == 0 && y == 0)){
            int m1 = x % 2;
            int m2 = y % 2;
            if(m1 != m2)
                count += 1;
            x = x / 2;
            y = y / 2;
        }
        return count;
    }
}
```