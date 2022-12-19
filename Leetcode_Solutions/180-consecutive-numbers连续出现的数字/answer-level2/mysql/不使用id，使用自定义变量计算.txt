如果Id不是连续的，根据Id计算会出现bug。或者是我对题意有误解。

以下是我的解题思路：

使用两个自定义变量，一个记录连续出现的次数Count，一个记录当前的出现的值Num。

case 1：如果Num = 当前的值，则代表连续出现，Count+ 1，Num不变

case 2：如果Num != 当前的值，则Count 清为1， Num 赋值为当前值。

代码如下：

```
select distinct temp.Num AS ConsecutiveNums from (
    select 
        Num,
        case
        when Num = @Num then @Count := @Count + 1
        when @Num := Num then @Count := 1
        else @Count := 1
        end as Count
    from
    Logs, (select @Count := 1, @Num := null) init
) as temp
where temp.Count > 2
```
