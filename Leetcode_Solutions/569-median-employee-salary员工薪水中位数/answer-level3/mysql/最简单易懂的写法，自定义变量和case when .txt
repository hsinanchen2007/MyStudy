
先用自定义变量分组排序，定义@num为序号，初始化为0，定义@last为上一行的部门，定义为null，
然后进行查询，@num:=if(@last!=Company,@num:=1,@num:=@num+1)   如果上一家公司不等于现在这家公司，就重置num为1，否则增加1
注意 需要先按公司排序 ，不然公司是乱的 序号就会不准

此时 这一步的时候，就得到了按分组排好序的数据
```
select Id,Company,Salary,@num:=if(@last!=Company,@num:=1,@num:=@num+1) as num,@last:=Company 
from 
(select Id,Company,Salary from Employee ) a ,
(select @num:=0,@last:=null) b  order by Company,Salary
) a
```


然后关联去取中位数， 先按公司分组，统计出最大条数，偶数的中位数的序号为 为** 最大数目/2 **和**最大数目/2+1 **
奇数的中位数为 **（最大数目+1）/2**

```
  select count(1) as countNum,Company,
       case when count(1)%2=0 then count(1)/2 else null end as o1 ,
       case when count(1)%2=0 then count(1)/2+1 else null  end as o2,
       case when count(1)%2=1 then (count(1)+1)/2 else null  end as o3
      from Employee group by Company

```


最后 用公司将这两个进行关联， 然后判断每组的数目是奇数还是偶数来取值



```
select Id,a.Company,Salary from 
(select Id,Company,Salary,@num:=if(@last!=Company,@num:=1,@num:=@num+1) as num,@last:=Company 
from 
(select Id,Company,Salary from Employee ) a ,
(select @num:=0,@last:=null) b  order by Company,Salary
) a
join 
(
      select count(1) as countNum,Company,
       case when count(1)%2=0 then count(1)/2 else null end as o1 ,
       case when count(1)%2=0 then count(1)/2+1 else null  end as o2,
       case when count(1)%2=1 then (count(1)+1)/2 else null  end as o3
      from Employee group by Company
) b  on a.Company=b.Company  where  num=if(countNum%2=1,o3,o2) or  num=if(countNum%2=0,o1,o3)

```



