### 解题思路
最开始写成if(@com = Company,@num :=@num+1,1)
没有更新Num,调了很久

### 代码

```mysql
# Write your MySQL query statement below
select ID,t1.company,salary  
From
    (
        select ID,Company ,if(@com = Company,@num :=@num+1,@num :=1) as num,salary,
        if(@com = Company,Company, @com := Company) as com
        from employee,(select @num:=1)b,(select @com:='')b1
        order by Company,salary
    )t1 
join
    (
        select company,count(*) as cum from employee group by company
    )t2
on  t1.company = t2.company
     and (t1.num=t2.cum/2 or t1.num =(t2.cum+1)/2 or t1.num =(t2.cum+2)/2)



```