```
select p.FirstName,p.LastName,a.City,a.State
from Person p left join Address a 
on p.PersonId=a.PersonId;
```


**连表查询**  
```
自连接：需要一表信息二循环遍历，通常会通过某些信息进行连接
外连接：需要两表信息二循环遍历，通常会通过某些信息进行连接，某些情况下可能需要左/右表信息完全要使用左/右外连接
```
**分组查询**
```
分组函数：count()计数，sum()求和，max()最大值，min()最小值，avg()平均值，sum()在浮点计算或者统计‘’=‘’的情况下用途比count()大
分组过滤：having可以对分组处理过的数据进行再筛选
```
**日期**
```
date('2020-01-27')将引号内的日期转化为日期对象，date_sub('2020-01-27',interval n day)将引号内的日期转化为字符串对应日期前n天的日期对象，date_add('2020-01-27',interval n day)将引号内的日期转化为字符串对应日期后n天的日期对象，日期判断是否在某区间内可以使用between 起始日期 and 中止日期
```
**浮点数字**
```
ifnull(double,x)：当double为null时返回x
round (double,n)：保留double后n位小数
```
