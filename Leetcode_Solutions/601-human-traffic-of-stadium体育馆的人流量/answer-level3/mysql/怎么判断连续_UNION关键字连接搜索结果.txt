```
# Write your MySQL query statement below
SELECT
    *
FROM
    (
    SELECT S1.*
    FROM
        stadium S1,
        stadium S2,
        stadium S3
    WHERE
        S1.id + 1 = S2.id
            AND
        S2.id + 1 = S3.id
            AND
        S1.people >= 100
            AND
        S2.people >= 100
            AND
        S3.people >= 100
    UNION
    SELECT
        S1.*
    FROM
        stadium S1,
        stadium S2,
        stadium S3
    WHERE
        S1.id - 1 = S2.id
            AND
        S1.id + 1 = S3.id
            AND
        S1.people >= 100
            AND
        S2.people >= 100
            AND
        S3.people >= 100
    UNION
    SELECT
        S1.*
    FROM
        stadium S1,
        stadium S2,
        stadium S3
    WHERE
        S1.id - 1 = S2.id
            AND
        S2.id - 1 = S3.id
            AND
        S1.people >= 100
            AND
        S2.people >= 100
            AND
        S3.people >= 100
    ) AS result   #如果没有别号，编译会不通过
ORDER BY
    result.id     #如果不排序，答案会出错
```
