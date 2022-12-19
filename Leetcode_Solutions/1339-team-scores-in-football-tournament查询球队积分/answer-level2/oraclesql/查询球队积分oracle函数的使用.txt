### 解题思路
     主场队伍和客场队伍在不同的两列,所以考虑分别计算每个队伍在主客场的得分再进行累加即可得到正确总分.

     子查询使用sum(decode(sign()))函数判断每场的得分情况并使用group by进行累加,
     再使用union all函数将主客场得分进行并集处理,得到每一场的主客场队伍得分情况,
     主查询中使用外连接保证每个team_id都有对应的分数,使用nvl()函数处理null值

### 代码

```oraclesql
/* Write your PL/SQL query statement below */
SELECT T.TEAM_ID, T.TEAM_NAME, NVL(SUM(T1.NUM_POINTS), 0) NUM_POINTS
  FROM TEAMS T,
       (SELECT HOST_TEAM TEAM_ID,
               SUM(DECODE(SIGN(HOST_GOALS - GUEST_GOALS), 0, 1, -1, 0, 3)) NUM_POINTS
          FROM MATCHES
         GROUP BY HOST_TEAM
        UNION ALL
        SELECT GUEST_TEAM TEAM_ID,
               SUM(DECODE(SIGN(HOST_GOALS - GUEST_GOALS), 0, 1, -1, 3, 0)) NUM_POINTS
          FROM MATCHES
         GROUP BY GUEST_TEAM) T1
 WHERE T.TEAM_ID = T1.TEAM_ID(+)
 GROUP BY T.TEAM_ID, T.TEAM_NAME
 ORDER BY NVL(SUM(T1.NUM_POINTS), 0) DESC, T.TEAM_ID
```