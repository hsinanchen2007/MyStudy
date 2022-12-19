### 解题思路
1.选择class内容根据class内容分类，用having对分类做进一步细分count计数选课数，DISTINCT用于去除单一学生对同一个课程的重复性选择。

### 代码

```mysql
# Write your MySQL query statement below
SELECT class
FROM courses
GROUP BY class
HAVING COUNT(DISTINCT student) >= 5;
```