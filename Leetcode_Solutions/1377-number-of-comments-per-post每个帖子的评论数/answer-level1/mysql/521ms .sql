```
SELECT s1.sub_id post_id,ifnull(COUNT(S2.sub_id),0) number_of_comments
FROM (SELECT DISTINCT sub_id FROM Submissions WHERE parent_id is null) s1 
LEFT JOIN (SELECT DISTINCT sub_id,parent_id FROM Submissions) s2 
ON s1.sub_id= s2.parent_id
GROUP BY s1.sub_id;
```
