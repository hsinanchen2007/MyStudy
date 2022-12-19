### 解题思路
自己设定两个变量，一个变量@pre用来记录前上一个数字是啥，并用来判断和当前数字是否相同，若相同则连续；另一个变量@c记录当前连续的次数，若碰到不连续的情况则需要重置为1.
```
 else @c:=1
```
上面这个代码是为了数字值为0的时候@pre=0返回的是假，不会执行@c:=1，所以利用else把这个例外去除。
另外因为不想用distinct，所以选择了先join再group by.

### 代码

```mysql
# Write your MySQL query statement below
select l1.Num as ConsecutiveNums
from Logs l1
join 
    (select Num, case 
    when @pre=Num then @c:=@c+1
    when @pre:=Num then @c:=1
    else @c:=1
    end as Counts
    from Logs l, (select @c:=1, @pre:=null) c) l2
    on l1.Num = l2.Num
where l2.Counts > 2
group by l1.Num
```