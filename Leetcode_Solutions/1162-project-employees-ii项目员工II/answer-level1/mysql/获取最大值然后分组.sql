### 解题思路
获取最大值然后分组 having再筛一遍就OK了
### 代码

```mysql
# Write your MySQL query statement below

select project_id from Project group by project_id having count(*) = 
(select count(*) `num` from Project group by project_id order by count(*) desc limit 1);


```