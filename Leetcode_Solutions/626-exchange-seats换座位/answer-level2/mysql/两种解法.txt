[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
奇数行关联下一个偶数行。偶数行关联上一个奇数行。

SQL逻辑：
```
SELECT *
FROM seat AS s1
LEFT JOIN seat AS s2 ON (S1.id % 2 = 1 AND S1.id+1 = S2.id OR S1.id % 2 = 0 AND S1.id-1 = S2.id)
```
如果最后一行是奇数行，其没有下一个偶数行，因此用left join保留此行。

其结果如下：
```
+------+---------+------+---------+
| id   | student | id   | student |
+------+---------+------+---------+
|    2 | Doris   |    1 | Abbot   |
|    1 | Abbot   |    2 | Doris   |
|    4 | Green   |    3 | Emerson |
|    3 | Emerson |    4 | Green   |
|    5 | Jeames  | NULL | NULL    |
+------+---------+------+---------+
```
从结果中看，只要将右边列的student值替换左边列的student即可。

第5行特殊处理。

合并上面的逻辑，得出：
```
SELECT 
S1.id, 
IF(
	S2.student IS NULL,
	S1.student,
	S2.student
) AS `student`
FROM seat AS s1
LEFT JOIN seat AS s2 ON (S1.id % 2 = 1 AND S1.id+1 = S2.id OR S1.id % 2 = 0 AND S1.id-1 = S2.id)
ORDER BY S1.id
```
# 解法二
在解法一中，要先确定行，再互换奇偶行的student。仅知道奇数行，但偶数行还没访问过，无法知晓其student值。

但是，可以互换奇偶行的id。题目明确说明“ 纵列的 id 是连续递增的 ”。

因此偶数行-1就是其奇数行，奇数行+1就是其偶数行。最后一行是奇数行时特殊处理一下即可。

SQL代码：
```
SELECT if(S.id % 2 = 0,
	S.id - 1,
	if(S.id = A.cnt,S.id,S.id+1)
) AS `id`,S.student
FROM seat AS S,(SELECT COUNT(*) AS `cnt` FROM seat) AS A
ORDER BY id
```
其中
```
(SELECT COUNT(*) AS `cnt` FROM seat) AS A
```
算出表中总行数。

奇偶行互换的逻辑：
```
if(S.id % 2 = 0,
	S.id - 1,
	if(S.id = A.cnt,S.id,S.id+1)
) AS `id`
```
注意到此题的id是从1开始的。如果id不是从1开始，而是从大于1的数开始，思路尽管相同。但要额外增加一个行id字段才可行。