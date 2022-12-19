### 解题思路
1.点在x轴，相邻两点最小距离即为 全部点最小距离
2.排序并计算相邻点距离
3.取距离最小值

### 执行用时
执行用时 :130 ms, 在所有 MySQL 提交中击败了99.31%的用户
应该比两表关联的解法效率高

### 代码

```mysql
# Write your MySQL query statement below

SELECT MIN(dis) AS shortest
FROM (
	SELECT @dis := if(@last_p IS NULL, NULL, x - @last_p) AS dis
		, @last_p := x
	FROM point, (
			SELECT @dis := NULL, @last_p := NULL
		) temp
	ORDER BY x ASC
) a
```