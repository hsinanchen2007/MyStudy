方法：
（1）按照部门分组，然后选取最大薪资；
（2）对（employee和department关联后的）表，筛选薪水出现在最大薪资的值即可；
这种情况出现的问题：当不同部门之间的筛选出的最大值与实际薪水值出现重复。具体假定：
A部门的职员薪水为6000，5000；B部门的薪水为5000，4000。则查询的结果会返回，A部分所有的职工信息和B部门薪水5000的职员，
在而真实的情况是只有两个职员（A的6000职员；和B的5000职员）；
所以，进行修改：
(3)首先对（1）修改，筛选出最大薪资及部门编号，然后将其与（2）中的表关联，
筛选条件为：职员薪水等于最大薪水（隐含着部门编号对应相等）。

具体查询语句如下：

```oracle []
/* Write your PL/SQL query statement below */
select tmp1.department,tmp1.name,tmp1.salary
from (select em.*,de.name department
    from employee em,department de
    where em.departmentid=de.id) tmp1,
    (
    select departmentid,max(salary) max_sal
    from employee
    group by departmentid) tmp2
where tmp1.departmentid=tmp2.departmentid
     and salary=tmp2.max_sal;
    
```

