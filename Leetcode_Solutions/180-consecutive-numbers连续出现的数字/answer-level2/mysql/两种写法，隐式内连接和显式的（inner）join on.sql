执行用时 : 772 ms, 在Consecutive Numbers的MySQL提交中击败了43.12% 的用户

内存消耗 : N/A

```sql
# Write your MySQL query statement below
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM (
    `Logs` AS l1 JOIN `Logs` AS l2 
    ON l1.Id = l2.Id - 1 && l1.num = l2.num
     ) JOIN `Logs` AS l3
    ON l2.Id = l3.Id - 1 && l2.num = l3.num
```

执行用时 : 614 ms, 在Consecutive Numbers的MySQL提交中击败了68.27% 的用户

内存消耗 : N/A

```sql
# Write your MySQL query statement below
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM `Logs` AS l1, `Logs` AS l2 , `Logs` AS l3
WHERE l1.Id = l2.Id - 1 && l1.num = l2.num && l2.Id = l3.Id - 1 && l2.num = l3.num
```

