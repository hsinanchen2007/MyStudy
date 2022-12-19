### 解题思路
1.因为是找到上升的温度的Id号，因此要表与自身做自然连接。
2.使用DATEDIFF(DATE1,DATE2)函数，函数的返回值未DATE1与DATE2的差值天数 DATE1 > DATE2 返回正整数 DATE1 < DATE2 返回负整数。

### 代码

```mysql
# Write your MySQL query statement below
SELECT w1.Id AS 'Id'
FROM weather w1 JOIN weather w2 ON DATEDIFF(w1.RecordDate,w2.RecordDate) = 1 
AND w1.Temperature > w2.Temperature;
```