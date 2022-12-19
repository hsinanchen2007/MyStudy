```
select e2.name as Employee from employee e1,employee e2
where e1.id=e2.managerid and e2.salary>e1.salary; 
```
比较令我吃惊的是，这个代码的效率居然这么低，看样子轻易不要使用这种方式去进行两表联合查询，效率不高
