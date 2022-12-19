### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numTrees(int n) {
        int[] result = new int[n + 1];
        result[0] = 1;
        result[1] = 1;

        for(int i = 2; i <= n;i++){
            for(int j = 1;j <= i;j++){
                result[i] += result[j - 1] * result[i - j]; 
            }
        }
        return result[n];
    }
}
```