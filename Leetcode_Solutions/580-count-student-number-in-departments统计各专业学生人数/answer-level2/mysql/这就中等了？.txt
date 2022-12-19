### 解题思路
太坑了

### 代码

```mysql
# Write your MySQL query statement below

select
    d.dept_name                                       dept_name
  , case when tmp.cnt is null then 0 else tmp.cnt end student_number
from
    department      d
        left join (
                  select dept_id, count(student_id) cnt
                  from student
                  group by dept_id
                  ) tmp on d.dept_id = tmp.dept_id
order by
    tmp.cnt desc, d.dept_name


```