1.第一步只能出现一次，对每个数字出现的次数进行判断，使用group by分组
    select num
    from my_numbers
    group by num

2.使用count函数得到每组的数量并且判断
    select num
    from my_numbers
    group by num
    having count(num) = 1
3.题目让获得最大的数字，对每组的数字进行倒序排序，并取第一个，就是最大的
    select num
    from my_numbers
    group by num
    having count(num) = 1
    order by num desc limit 1
4.当查不到时，返回null，使用ifnull函数对查询结果进行处理
    select ifnull((select num
    from my_numbers
    group by num
    having count(num) = 1
    order by num desc limit 1),null) as num