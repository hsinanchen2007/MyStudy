### 解题思路
想着可以用String转int来处理，看看题目发现，这样接替是不可以的，老老实实用求模迭代的处理方法

### 代码

```java
class Solution {
     public int reverse(int x) {
        long temp = 0;

        while(x != 0){
            int pop = x % 10;
            temp = temp * 10 + pop;

            if(temp > Integer.MAX_VALUE || temp < Integer.MIN_VALUE){
                return 0;
            }
            x /= 10;
        }
        return (int)temp;
    }

}
```