### 解题思路
此处撰写解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
47.7 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        int cnt = 1;
        while (n-- != 0) cnt *= 10; 
        int[] res = new int[cnt-1]; 
        for(int i = 0; i < cnt - 1; i++){
            res[i] = i + 1;
        }
        return res;
    }
}
```