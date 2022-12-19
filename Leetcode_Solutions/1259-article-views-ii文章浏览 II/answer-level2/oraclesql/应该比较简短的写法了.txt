```
/* Write your PL/SQL query statement below */
SELECT DISTINCT viewer_id AS id
FROM Views a
GROUP BY a.view_date, viewer_id
HAVING COUNT(DISTINCT article_id) >= 2
ORDER BY viewer_id
```
