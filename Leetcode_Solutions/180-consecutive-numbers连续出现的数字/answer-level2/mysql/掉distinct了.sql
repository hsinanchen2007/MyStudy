### 解题思路
 select a.num ConsecutiveNums  from logs a,logs b,logs c
where 
 a.id=b.id-1 and 
 b.id=c.id-1 and
 a.num=b.num and
 b.num=c.num
这是我一开始的解法，因为没有考虑连续的超过三个的情况，就会输出【3】【3】的情况，这个时候别忘记distinct，将重复的去重一下就行
### 代码

```mysql
# Write your MySQL query statement below

 select distinct(a.num) ConsecutiveNums  from logs a,logs b,logs c
where 
 a.id=b.id-1 and 
 b.id=c.id-1 and
 a.num=b.num and
 b.num=c.num

```