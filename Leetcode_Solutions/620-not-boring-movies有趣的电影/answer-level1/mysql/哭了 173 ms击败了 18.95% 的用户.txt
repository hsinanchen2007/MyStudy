### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
SELECT id,movie,description,rating from cinema 
WHERE id%2 = 1 and description !="boring"
order by rating desc
```