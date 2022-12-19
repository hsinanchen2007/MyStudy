```mysql []
SELECT DISTINCT
    lc.seat_id AS seat_id
FROM
    cinema lc
        JOIN
    cinema rc ON ABS(lc.seat_id - rc.seat_id) = 1
        AND lc.free = TRUE
        AND rc.free = TRUE
ORDER BY lc.seat_id;
```
