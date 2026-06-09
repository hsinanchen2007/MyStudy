1. **employee表排序**
    对employee表排序，这里采用多列排序。首先我们排序部门（升序降序都可以），然后排序薪资（降序），这样每个部门的前三薪资就出来了。
2. **通过自变量标注每一行在当前部门的排名**
    这里我们需要三个自变量，两个辅助判断，一个标注名次
    @a用于判断名次
    @x用于判断当前部门是否和上一行的部门一样，不一样，那么我们就要重置@a的名次了
    @y用于判断薪资，和上一行的薪资对比，不一样，我们就对当前行的名次+1

以下是代码，逻辑很清晰。

**这里有一个注意点，自变量的顺序，@a一定要在最前面。**

```
select
    department.`name` as `department`,
    sub4.`name` as `employee`,
    sub4.salary as `salary`
from
    (
    select
        `id` ,
        `departmentid` ,
        `name`, 
        salary,
        @a := if( @x = departmentid ,  @a + if(@y=salary,0,1) ,  1 ) as sub3,
        @x := departmentid as sub1 ,
        @y := salary as sub2
    from
        employee,
        (select @x:=0 , @y := 0 , @a := 0) as sub 
    order by
        departmentid asc,
        salary desc
    ) as sub4
join
    department
on
    department.id = sub4.departmentid
    and
    sub4.sub3 < 4 ;
```