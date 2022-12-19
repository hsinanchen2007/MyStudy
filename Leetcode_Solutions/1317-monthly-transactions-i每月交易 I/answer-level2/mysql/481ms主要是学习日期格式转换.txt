### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below

#日期格式转换
select month   ,country,coUNt(*) as trans_count,
sum(approved_count) as approved_count,sum(amount) as trans_total_amount,
sum(approved_count*amount) as approved_total_amount
FROM
    (SELECT id,country,amount,
    if(state="approved",1,0) as approved_count,
    DATE_FORMAT(trans_date,'%Y-%m')  AS month
    from Transactions) A
GROUP BY month,country ORDER BY month,country 
```