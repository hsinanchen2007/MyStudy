### 解题思路
此处撰写解题思路
模拟
执行用时 :
874 ms
, 在所有 Java 提交中击败了
10.99%
的用户
内存消耗 :
46 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int len = updates.length;
        int[] res = new int[length];
        for (int i = 0; i < len; i++){
            for (int j = updates[i][0]; j <= updates[i][1]; j++){
                res[j] += updates[i][2];
            }
        }
        return res;
    }
}
```