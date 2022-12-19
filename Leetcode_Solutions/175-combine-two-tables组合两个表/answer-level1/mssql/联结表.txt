最近正好复习数据库期末考试，就来leetcode刷道题了，这个题就是考联结表，题目说了无论人物是否有地址信息都要把人物给打印出来所以我们进行左联结，这样左边的表的信息就会被全部包含，两个表都有PersonId这列所以这就是联结条件，代码如下
select p.FirstName, p.LastName, a.City, a.State 
from Person as p left join Address as a 
on p.PersonId = a.PersonId