为什么不加group by class 就运行错误了呢？
select class from courses group by class having count(distinct student) >= 5;