执行用时 :149 ms, 在所有 MySQL 提交中击败了51.03%的用户
内存消耗 :0B, 在所有 MySQL 提交中击败了100.00%的用户
```
SELECT MIN(p1.x - p2.x) AS shortest
FROM point AS p1, point AS p2
WHERE p1.x > p2.x
```
