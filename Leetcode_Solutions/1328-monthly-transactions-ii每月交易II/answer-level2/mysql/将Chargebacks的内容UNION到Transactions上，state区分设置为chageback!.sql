SELECT date_format(trans_date,'%Y-%m') AS month,
country,
COUNT(IF(state = 'approved',id,null)) AS approved_count,
SUM(IF(state = 'approved',amount,0)) AS approved_amount,
COUNT(IF(state = 'chargeback',id,null)) AS chargeback_count,
SUM(IF(state = 'chargeback',amount,0)) AS chargeback_amount

FROM 
    (
    SELECT *
    FROM Transactions
    WHERE state = 'approved'
    UNION ALL
    SELECT c.trans_id AS id,
    t.country as country,
    'chargeback' AS state ,t.amount AS amount,
    c.trans_date AS trans_date ,
    FROM Chargebacks AS c LEFT JOIN Transactions AS t ON c.trans_id = t.id
    ) 
AS a

GROUP BY country,date_format(trans_date,'%Y-%m');

解题思路：
1.题目要求按国家和月份分类，如果JOIN两个表，他们的月份就不对等了，所以考虑UNION两个表，chargebacks表中的内容新增的state为chargeback，这样就可以跟transactions中的内容区分开来。
2.接下来就是以country，以及month分组求和以及计数的事情了，这里用COUNT(IF)和SUM(IF)就能算出来。
3.declined信息再题目中没有用处，可以再第一步就去除了他，如果不去除的话，SELECT出来的内容会出现四个0的情况。