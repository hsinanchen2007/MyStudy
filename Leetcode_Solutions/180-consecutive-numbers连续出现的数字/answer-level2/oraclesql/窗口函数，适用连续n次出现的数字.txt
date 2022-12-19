需要求连续n次，直接把count(1) >= 3替换成count(1) >= n

```
select distinct Num ConsecutiveNums
from (
    select Num, (Id - rn) diff, count(1)
    from (
        select Id, Num, row_number() over(partition by Num order by Id asc) rn
        from Logs
        ) t1
    group by Num, (Id - rn)
    having count(1) >= 3
    ) t2
;
```
![image.png](https://pic.leetcode-cn.com/35dd71d87a325b67af2303949530f2cf259e439f0e2662c0540baa9ff8f04a08-image.png)
