```sql
SELECT query_name, ROUND(AVG(unavg_quality), 2) AS quality, 
    ROUND(AVG(poor_query) * 100, 2) AS poor_query_percentage
FROM
(
SELECT query_name, rating, rating/position AS unavg_quality, 
    IF(rating >= 3, 0, 1) AS poor_query
FROM Queries
) AS temp
GROUP BY query_name;
```