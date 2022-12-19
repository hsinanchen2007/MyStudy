### 代码
```oraclesql
SELECT A.AD_ID,
       ROUND(100 * SUM(DECODE(A.ACTION, 'Clicked', 1, 0)) /
             DECODE((SUM(DECODE(A.ACTION, 'Clicked', 1, 0)) +
                    SUM(DECODE(A.ACTION, 'Viewed', 1, 0))),
                    0,
                    1,
                    (SUM(DECODE(A.ACTION, 'Clicked', 1, 0)) +
                    SUM(DECODE(A.ACTION, 'Viewed', 1, 0)))),
             2) CTR
  FROM ADS A
 GROUP BY A.AD_ID
 ORDER BY CTR DESC, A.AD_ID
```