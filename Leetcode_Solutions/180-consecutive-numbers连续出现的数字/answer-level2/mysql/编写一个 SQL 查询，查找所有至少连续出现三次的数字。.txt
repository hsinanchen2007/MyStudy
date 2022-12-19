### 解题思路
```
#①首先遍历一遍整张表，找出每个数字的连续重复次数
#具体方法为：
    #初始化两个变量，一个为pre，记录上一个数字；一个为count，记录上一个数字已经连续出现的次数。
    #然后调用if()函数，如果pre和当前行数字相同，count加1极为连续出现的次数；如果不同，意味着重新开始一个数字，count重新从1开始。
    #最后，将当前的Num数字赋值给pre，开始下一行扫描。
    select 
        Num,    #当前的Num 数字
        if(@pre=Num,@count := @count+1,@count := 1) as nums, #判断 和 计数
        @pre:=Num   #将当前Num赋值给pre
    from Logs as l ,
        (select @pre:= null,@count:=1) as pc #这里需要别名
    #上面这段代码执行结果就是一张三列为Num,count as nums,pre的表。

#②将上面表的结果中，重复次数大于等于3的数字选出，再去重即为连续至少出现三次的数字。
    select 
        distinct Num as ConsecutiveNums 
    from  
        (select Num,
                if(@pre=Num,@count := @count+1,@count := 1) as nums,
                @pre:=Num
            from Logs as l ,
                (select @pre:= null,@count:=1) as pc
        ) as n
    where nums >=3;

#注意：pre初始值最好不要赋值为一个数字，因为不确定赋值的数字是否会出现在测试表中。
```


### 代码

```mysql
# Write your MySQL query statement below
select 
    distinct Num as ConsecutiveNums 
from  
    (select Num,
            if(@pre=Num,@count := @count+1,@count := 1) as nums,
            @pre:=Num
        from Logs as l ,
            (select @pre:= null,@count:=1) as pc
      ) as n
where nums >=3;
```