### 解题思路
1、原表添加一列数据flag做标记，用标记分组，打印count(1)>=3 
2、遇到people <100,记flag=1 ，计算方法length((@flag1:=@flag1 +1)div 10)永远等于1，同时给@flag自加1；
3、遇到people >=100,记flag=@flag，连续遇到people >=100都给同一个@flag，
4、分组计数打印；
5、flag列 样式 2 2 1 1 4 4 4 4 1 1 6 6 6 1 容易看出峰值就是 4444,666这样的字段

### 代码

```mysql
# Write your MySQL query statement below
select id,visit_date,people 
from(
        select *,if(people <100,length((@flag1:=@flag1 +1)div 10),@flag1) flag 
        from stadium,(select @flag1:= 2) t
    ) as t
where flag in(
                select flag 
                from(
                        select *,if(people <100,length((@flag2:=@flag2 +1)div 10),@flag2) flag 
                        from stadium,(select @flag2:= 2) t
                    ) as t
                group by flag
                having count(1)>=3 and flag != 1
             )

```