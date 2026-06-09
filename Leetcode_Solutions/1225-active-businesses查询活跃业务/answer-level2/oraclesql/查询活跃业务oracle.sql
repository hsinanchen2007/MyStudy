### 解题思路
        先计算出每个类型事件发生的平均值,外连接到events表,
        用DECODE(SIGN())标记大于平局值的BUSINESS_ID,
        再筛选出有2个以上大于平均值的BUSINESS_ID即可
### 代码

```oraclesql
/* Write your PL/SQL query statement below */
SELECT BUSINESS_ID
  FROM (SELECT S.BUSINESS_ID, SUM(S.SIGN) SUM
          FROM (SELECT E.*,
                       T.*,
                       DECODE(SIGN(E.OCCURENCES - T.AVG), 1, 1, 0) SIGN
                  FROM EVENTS E,
                       (SELECT EVENT_TYPE ET,
                               SUM(OCCURENCES) / COUNT(EVENT_TYPE) AVG
                          FROM EVENTS
                         GROUP BY EVENT_TYPE) T
                 WHERE E.EVENT_TYPE = T.ET(+)) S
         GROUP BY S.BUSINESS_ID) T
 WHERE T.SUM >= 2

```