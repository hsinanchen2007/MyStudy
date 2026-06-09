1. .....
2. 不同部门的顺序从1开始，后续薪水有变化顺序加，否则不变。 
3. 用三个变量，分别 dept-上一条记录的部门，prev-上一条记录的薪水，rank-排名
4. 先后按照部门顺序，薪水降序 排序， 使数据按部门分组且组内薪水降序
5. case when 控制 与上一次部门不同时的rank从1开始， 当与上一个部门相同时，与上一次的薪水对比 与上次薪水相同时，rank 不变，比上次少时，rank +1
select  d.name Department,re.name Employee, re.salary Salary from 
department d left join 
(
select @rank := 
    case 
         when @dept = e.departmentid then if(@prev > salary,@rank+1,@rank) 
         else  1 
    end

    rank,
    @prev := salary salary,
    e.name ,
    @dept := departmentid departmentid
     
    from employee e,(select @rank:=1,@dept:=null,@prev:=null) init 
    order by departmentid, salary desc,id 
) re  on d.id=re.departmentid 
where re.rank < 4