![image.png](https://pic.leetcode-cn.com/522c0a802fb11b4a6e42689c48f35c15e035214bff336c81a251d5e6187fca18-image.png)
SELECT
    Request_at DAY,
    ROUND(
        SUM(IF(
    STATUS
        <> 'completed',
        1,
        0
    )) / COUNT(1),
        2
    ) 'Cancellation Rate'
FROM
    Trips t
LEFT JOIN Users u1 ON
    Client_id = u1.Users_id
LEFT JOIN Users u2 ON
    Driver_id = u2.Users_id
WHERE
    u1.Banned = 'No' AND u2.Banned = 'No' AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY
    Request_at