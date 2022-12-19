```
SELECT month as MONTH,
       country as COUNTRY,
       SUM(IF(type = 'approved', 1, 0)) AS APPROVED_COUNT,
       SUM(IF(type = 'approved', amount, 0)) AS APPROVED_AMOUNT,
       SUM(IF(type = 'chargeback', 1, 0)) AS CHARGEBACK_COUNT,
       SUM(IF(type = 'chargeback', amount, 0)) AS CHARGEBACK_AMOUNT
FROM (
        (SELECT date_format(t.trans_date,'%Y-%m') AS month,
                t.country,
                amount,
                'approved' AS type
         FROM Transactions AS t
         WHERE state = 'approved' )
      UNION ALL
        (SELECT date_format(c.trans_date,'%Y-%m') AS month,
                t.country,
                amount,
                'chargeback' AS type
         FROM Transactions AS t
         INNER JOIN Chargebacks AS c ON t.id = c.trans_id)) AS tt
GROUP BY tt.month,
         tt.country;
```

