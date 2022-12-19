### 解题思路
使用除法，不要使用乘法，否则会产生越界现象

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        int i = 1;
        while(true){
            if(x/i == i || (x/i>i && x/(i+1)<i+1)){
                break;
            }
            i++;
        }
        return i;
    }
}
```