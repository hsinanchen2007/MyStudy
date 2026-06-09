### 解题思路
select email  from person  having count(email)>=2这样也能出来结果，我惊奇了，having竟然不需要搭配group by也能用，但是一旦出现没有重复的，好像就随便出一个，但是加了group by之后需要对where 和 having的过滤条件负责，出得结果就正确～


### 代码

```mysql
# Write your MySQL query statement below
select email from person group by Email having count(email)>=2

```