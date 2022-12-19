使用分组统计
对Email字段进行分组
必须使用having过滤，不能使用where，因为where执行优先级大于聚集函数

'''
select Email
from Person as p
group by Email
having count(Email) >= 2 ;
'''