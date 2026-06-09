### 解题思路
通过运用自变量对日期和温度做运算，为比前一天温度要高的日期置flag为1后，再对临时表进行where筛选出flag为1的ID

### 代码

```mysql
# Write your MySQL query statement below
select Id
from
    (select w1.*,@flag:=if(@prev_t<Temperature and DateDiff(RecordDate,@prev_d) = 1,1,0) as Flag,@prev_t:=Temperature as prev,@prev_d:=RecordDate
    from
    (select * from Weather order by RecordDate) as w1,(select @flag:=0,@prev_t:=999,@prev_d:=0) as w2) as temp
where flag = 1
```