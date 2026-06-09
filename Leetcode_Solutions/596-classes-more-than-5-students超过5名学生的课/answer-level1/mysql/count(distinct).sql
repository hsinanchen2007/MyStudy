### 解题思路
此题难度不大，但是count中的distinct我是抱着尝试的心态写的，对语法还不太熟练。

### 代码

```mysql
# Write your MySQL query statement below
select class from courses
group by class
having count(distinct student) >= 5;
```