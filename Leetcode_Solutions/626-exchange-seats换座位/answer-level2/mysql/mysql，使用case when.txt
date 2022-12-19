```
select s1.id,
    (case 
        when s1.id % 2 = 0 
        then (select s2.student from seat s2 where s2.id = s1.id - 1)

        when (tempMax.maxid = s1.id)
        then (select s2.student from seat s2 where s2.id = s1.id)
     
        else (select s2.student from seat s2 where s2.id = s1.id + 1)
    end)
    as student
from seat s1,(select max(id) as maxid from seat) as tempMax

```

建立了一个tempMax的临时表存放最大id，匹配时如果发现偶数id最大时则返回当前 id相关的student值
