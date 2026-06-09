思路1：使用子查询计算重复合作的演员和导演记录
```sql
SELECT DISTINCT a1.actor_id AS ACTOR_ID, a1.director_id AS DIRECTOR_ID
FROM ActorDirector AS a1
WHERE (SELECT COUNT(1) 
            FROM ActorDirector AS a2
            WHERE a1.actor_id = a2.actor_id
            AND a1.director_id = a2.director_id
           ) > 2;
```
思路2：也是效率相对更高的做法，对演员和导演id分组和计数
```sql
SELECT actor_id AS ACTOR_ID, director_id AS DIRECTOR_ID
FROM ActorDirector 
GROUP BY actor_id, director_id
HAVING COUNT(1) > 2;
```