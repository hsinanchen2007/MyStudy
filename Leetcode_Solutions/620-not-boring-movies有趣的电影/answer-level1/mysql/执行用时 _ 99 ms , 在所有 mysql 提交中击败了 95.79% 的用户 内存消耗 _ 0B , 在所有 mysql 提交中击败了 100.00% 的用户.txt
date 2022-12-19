### 解题思路
1:奇数
2：where条件
3：排序：倒序

### 代码

```mysql
# Write your MySQL query statement below
select *  from cinema where id%2=1 and description!='boring' ORDER BY rating desc 
```