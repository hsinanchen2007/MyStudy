### 解题思路
这题好像和之前一道数论的题有点类似。意思就是小的质因数是可以凑成大质因数的。所以不断地从小往大进行更新就可以了。

### 代码

```java
class Solution {
    public boolean isUgly(int num) {
        if(num < 1)
            return false;
        
        while(num > 1){
            if(num % 2 == 0)
                num = num / 2;
            else if(num % 3 == 0)
                num = num / 3;
            else if(num % 5 == 0)
                num = num / 5;
            else
                return false;
        }
        return true;
    }
}
```