### 解题思路

![image.png](https://pic.leetcode-cn.com/ec3effaae38e52b4931d8907224e96a75b371105df225ed3f51920ec90e05b17-image.png)

### 代码

```java
class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        Map<Integer,Integer> map = new HashMap<>();
        for (int i = 0; i < B.length; i++) {
            map.put(B[i],i);
        }
        for (int i = 0; i <  A.length; i++) {
            A[i] = map.get(A[i]);
        }
        return A;
    }
}
```