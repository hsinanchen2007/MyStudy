### 解题思路
为啥效率这么低阿，我一直觉得exists效率不是很高的吗，求解答。
这道题一开始我直接用date做的减法，样例居然可以过，挺神奇的，想知道date做减法会是什么效果
### 代码

```mysql
# Write your MySQL query statement below
select id from weather w1
where exists(
    select * from weather w2
    where datediff(w2.recorddate,w1.recorddate)=-1 and w2.temperature<w1.temperature
);
```