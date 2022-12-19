







```
SELECT login_date, COUNT(user_id) user_count FROM 

    (
        SELECT user_id, MIN(activity_date) AS login_date
        FROM Traffic
        WHERE activity = 'login' 
        GROUP BY user_id
    )temp
    
WHERE login_date >= DATE_SUB('2019-06-30',INTERVAL 90 DAY)

GROUP BY login_date

ORDER BY login_date

```


