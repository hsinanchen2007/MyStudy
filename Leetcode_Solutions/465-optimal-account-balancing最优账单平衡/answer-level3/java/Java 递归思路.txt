### 解题思路

先把所有人的钱的正负都放到一个数组里。
然后从第一个人开始，找到钱数的正负和他不一样的人，试图把第一个人的钱都放到另外一个人身上。
然后for循环第二个人一直到第n个

### 代码

```java
class Solution {
    int[] acc;
    int res = Integer.MAX_VALUE;
    int n;
    public int minTransfers(int[][] transactions) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < transactions.length; i ++) {
            int first = transactions[i][0];
            int second = transactions[i][1];
            int amount = transactions[i][2];
            map.put(first, map.getOrDefault(first, 0) - amount);
            map.put(second, map.getOrDefault(second, 0) + amount);
        }
        acc = map.values().stream().mapToInt(i -> i).toArray();
        this.n = acc.length;        
        helper(0, 0);
        return res;
    }

    void helper(int start, int cnt) {
        while (start < n && acc[start] == 0) {
            start ++;
        }
        if (start == n) {
            res = Math.min(res, cnt);
            return;
        }
        for (int i = start + 1; i < n; i ++) {
            if (acc[i] < 0 && acc[start] > 0 || acc[start] < 0 && acc[i] > 0) {
                acc[i] += acc[start];
                helper(start + 1, cnt + 1);
                acc[i] -= acc[start];
            }
        }
    }
}
```