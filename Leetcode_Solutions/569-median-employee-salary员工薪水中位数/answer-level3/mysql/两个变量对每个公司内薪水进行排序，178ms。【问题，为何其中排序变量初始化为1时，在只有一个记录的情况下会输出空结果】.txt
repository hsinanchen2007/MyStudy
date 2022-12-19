### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
#（1）使用两个变量，对每个公司内的薪水进行排序，并增加新列来标记；
#（2）算出每个公司的人数
#（3）内连接只取每个公司的中间值，即num/2或num+1 /2 :如果是奇数，两个结果相同；偶数时，两个不同结果


        select   
                 c.id,
                 c.company,
                 c.salary
        from 
            (   
                    #步骤1：各公司内部按薪水排序
                 select  a.id,
                         a.company,
                         a.salary,
                        (if(@pre=a.company,@con:=@con+1,@con:=1) )as neworder,
                        @pre:=a.company
                     from Employee as a,(select @con:=0,@pre:=0)as b   
                     order by a.company,a.salary
            )as c
        join
            (
            #步骤2：算出每个公司的总人数
                select  company,
                        count(*) as totalnum
                from Employee as e
                group by company
            )as d
        #步骤三：内连接条件
        on 
            c.company=d.company 
            and
            (
                c.neworder in (round(totalnum/2,0),round((totalnum+1)/2,0))
            )
```