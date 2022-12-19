### 解题思路
n是奇数，结果：[-n/2,n/2]
n是偶数，结果：[-n/2, ……, -1, 1, ……, n/2]
### 代码

```java
class Solution {
    public int[] sumZero(int n) {
        int[] res = new int[n];
        int index = 0;
        for(int i = n/2; i > 0 ; i--){
            res[index++] = -i;
            res[n-index] = i;
        }
        return res;
    }
}
```