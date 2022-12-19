### 解题思路
此处撰写解题思路
执行用时 :
1364 ms
, 在所有 Java 提交中击败了
5.05%
的用户
内存消耗 :
41.4 MB
, 在所有 Java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        ArrayList<Integer> res = new ArrayList<>(n);
        for (int i = 0; i < n; i++){
            res.add(i);
        }
        int idx = 0;
        while (n > 1){
            idx = (m + idx - 1) % n;
            res.remove(idx);
            n--;
        }
        return res.get(0);
    }
}
```