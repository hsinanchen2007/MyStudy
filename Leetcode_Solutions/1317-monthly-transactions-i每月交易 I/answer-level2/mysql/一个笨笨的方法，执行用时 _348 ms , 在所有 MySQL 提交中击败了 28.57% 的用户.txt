SELECT t1.month, t1.country, t1.trans_count, IFNULL(t2.approved_count,0) AS approved_count, 
       t1.trans_total_amount, IFNULL(t2.approved_total_amount,0) AS approved_total_amount 
FROM (
    SELECT country, DATE_FORMAT(trans_date, "%Y-%m") AS month, 
           COUNT(id) AS trans_count, SUM(amount) AS trans_total_amount
    FROM Transactions
    GROUP BY country, month
    ) t1
LEFT JOIN 
    (
        SELECT country, DATE_FORMAT(trans_date, "%Y-%m") AS month,
        COUNT(id) AS approved_count, SUM(amount) AS approved_total_amount 
        FROM Transactions
        WHERE state = 'approved'
        GROUP BY month, country
    ) t2
ON t1.country = t2.country AND t1.month = t2.month
ORDER BY t1.month;
