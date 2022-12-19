### 方法一：先连接后筛选 ###
#### 思路 ####
- 根据`num`列相等对`logs`表进行自连接
- 根据`l1.id`进行聚合分组
- 若分组中满足`l1.id`与`l2.id`的差在`0`到`2`之间的`l2.id`大于`2`个，则说明该`num`连续出现`3`次
#### 代码 ####
```mysql []
select distinct l1.num consecutivenums
from logs l1 join logs l2
on l1.num = l2.num
group by l1.id
having sum(l1.id - l2.id between 0 and 2) > 2
```
### 方法二：先筛选后连接 ###
#### 思路 ####
- 根据`num`列相等，以及`id`之差的范围在`0`到`2`之间，对`logs`表进行自连接
- 根据`l1.id`进行聚合分组
- 统计分组中`l2.id`的数目，若大于`2`即满足题意
#### 代码 ####
```mysql []
select distinct l1.num consecutivenums
from logs l1 join logs l2
on l1.num = l2.num and l1.id - l2.id between 0 and 2
group by l1.id
having count(l2.id) > 2
```