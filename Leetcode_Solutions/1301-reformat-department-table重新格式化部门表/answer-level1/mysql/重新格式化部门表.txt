### 解题思路
分组，聚合

### 代码

```mysql
SELECT  id,
	  SUM(CASE WHEN MONTH='Jan'THEN revenue END)AS Jan_Revenue,SUM(CASE WHEN MONTH='Feb'THEN revenue END)AS Feb_Revenue,
	  SUM(CASE WHEN MONTH='Mar'THEN revenue END)AS Mar_Revenue,SUM(CASE WHEN MONTH='Apr'THEN revenue END)AS Apr_Revenue,
	  SUM(CASE WHEN MONTH='May'THEN revenue END)AS May_Revenue,SUM(CASE WHEN MONTH='Jun'THEN revenue END)AS Jun_Revenue,
	  SUM(CASE WHEN MONTH='Jul'THEN revenue END)AS Jul_Revenue,SUM(CASE WHEN MONTH='Aug'THEN revenue END)AS Aug_Revenue,
	  SUM(CASE WHEN MONTH='Sep'THEN revenue END)AS Sep_Revenue,SUM(CASE WHEN MONTH='Oct'THEN revenue END)AS Oct_Revenue,
	  SUM(CASE WHEN MONTH='Nov'THEN revenue END)AS Nov_Revenue,SUM(CASE WHEN MONTH='Dec'THEN revenue END)AS Dec_Revenue
FROM Department
GROUP BY id
ORDER BY id;
```