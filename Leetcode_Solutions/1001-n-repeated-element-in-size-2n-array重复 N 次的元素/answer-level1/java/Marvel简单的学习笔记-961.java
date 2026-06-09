### 解题思路
只要找到重复的元素就返回。

时间复杂度：O(n)。
空间复杂度：本题直接开了一个长度为10000的数组，因此空间复杂度为O(1)。若使用Map，则空间复杂度为O(n)。

### 代码

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        boolean[] hash = new boolean[10000];
        int i;
        for(i = 0; i < A.length; i++)
        {
            if(hash[A[i]]) break;
            hash[A[i]] = true;
        }
        return A[i];
    }
}
```