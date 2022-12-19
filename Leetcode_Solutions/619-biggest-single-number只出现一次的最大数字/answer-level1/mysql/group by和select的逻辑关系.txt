`# 正确写法
select max(num) as num from

(select 
    num
from  
    my_numbers 
group by num
having count(num) = 1) a`


错误写法：
`
select 
    max(num)  # 此处会分别打印出groupby后每个分组的最大值
from  
    my_numbers 
group by num
having count(num) = 1`
