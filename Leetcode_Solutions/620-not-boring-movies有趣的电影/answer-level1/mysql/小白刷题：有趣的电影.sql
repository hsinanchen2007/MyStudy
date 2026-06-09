基础查询排序，注意SQL中没有%，取余利用mod()函数

代码：
```
select * from cinema 
where description != 'boring' and mod(id, 2) = 1
order by rating desc
```
