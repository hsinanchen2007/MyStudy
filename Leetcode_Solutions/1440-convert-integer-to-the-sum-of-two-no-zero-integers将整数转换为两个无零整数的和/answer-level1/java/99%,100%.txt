### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
        int [] res = new int[2];
        res[0] = 1;
        res[1] = n - 1;
        if (n >= 1000) {
            while (res[0] % 10 == 0 || res[0] % 100 <= 10 || res[0] % 1000 <= 100 ||
                    res[1] % 10 == 0 || res[1] % 100 <= 10 || res[1] % 1000 <= 100) {
                res[0]++;
                res[1]--;
            }
        }
        else if (n >= 100){
            while (res[0] % 10 == 0 || res[0] % 100 <= 10 ||
                    res[1] % 10 == 0 || res[1] % 100 <= 10) {
                res[0]++;
                res[1]--;
            }
        }
        else if (n >= 10){
            while (res[0] % 10 == 0 || res[1] % 10 == 0) {
                res[0]++;
                res[1]--;
            }
        }
        return res;
    }
}
```