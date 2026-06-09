```
SELECT DISTINCT a.`id`,a.`visit_date`,a.`people` FROM stadium AS a
RIGHT JOIN (
	SELECT s1.`id` FROM 
	stadium s1,stadium s2,stadium s3
	WHERE s1.`id` = s2.`id` - 1 AND s2.`id` = s3.`id` - 1 AND s1.`people` >= 100 AND s2.`people` >= 100 AND s3.`people` >= 100
) AS b ON a.`id` >= b.id AND a.`id` <= b.id + 2
```
