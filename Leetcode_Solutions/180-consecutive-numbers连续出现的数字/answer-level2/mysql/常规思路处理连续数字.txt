### 解题思路
对于本题的处理，我的方法很正常，也很简单，中规中矩，没什么好说的
不过我对这个题曾经尝试引入变量去解决，但是我发现我对变量掌握的还是不够熟悉，如果有哪个大佬能给点资源去学习一下的话，我感激不尽
我发现这种有一些难度的题都是如果从高级程序语言，编程的角度去解决的话都是比较容易的，但是到SQL中因为其语句功能的高集成性反而导致不容易下手，利用关系代数连接多表一般都比较慢，所以我觉得真正好用的还是通过引入变量的思路去解决问题

### 代码

```mysql
# Write your MySQL query statement below
select distinct(l1.Num) as ConsecutiveNums
from 
    logs l1,
    logs l2,
    logs l3
where
    l1.Num=l2.Num and
    l2.Num=l3.Num and
    l1.id=l2.id-1 and
    l2.id=l3.id-1
;
```