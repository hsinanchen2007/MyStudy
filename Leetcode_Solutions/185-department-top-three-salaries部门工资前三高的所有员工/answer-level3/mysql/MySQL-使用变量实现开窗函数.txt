MySQL8.0之前没有开窗函数，因此实现分组排序要么通过多次join，要么通过变量实现。

多次join会降低执行效率，这里给出使用变量实现开窗函数的方法。

```
SELECT d.name as Department, t.name as Employee, t.salary 
FROM (
    SELECT 
        e.name, 
        case when @d=e.departmentid then case when e.salary<@s then @c:=@c+1 else @c end else @c:=1 end as cnt, 
        @s:=e.salary as salary,
        @d:=e.departmentid as departmentid 
    FROM employee as e 
    order by e.departmentid,e.salary desc
    )as t 
JOIN department as d 
ON d.id=t.departmentid 
WHERE t.cnt<=3 order by department,salary desc;
```


