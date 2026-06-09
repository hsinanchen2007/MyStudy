1、问题分析：查询每个员工最近三个月的累计薪水（不含当前月）
那么联合两表（命名e1,e2）join,只用Join的话，是n*n条记录。然后筛选出e1的id等于e2的id且e1的月份大于e2的月份。这样等于拿到了，每个id的最大月份和其他月份的组合。r
如：比如一个人总的发了4次薪水，组合为：4,1;4,2;4,3
2、接下来是分组计算：以e1的id与month作分组，为什么呢？因为前面有做筛选，对于某个id,可以将比e1小的月份的薪水都拿出来求和。
sql如下：
select e1.id,max(e2.month) as month,sum(e2.salary) as salary from employee e1 join employee e2
where e1.id=e2.id and e1.month>e2.month
and e1.month-e2.month<=3
group by e1.id,e1.month order by e1.id,max(e2.month) desc