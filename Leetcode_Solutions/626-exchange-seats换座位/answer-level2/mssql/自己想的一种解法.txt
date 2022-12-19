分解为三种情况：
1、单数id，取比它大1的双数id的student
2、双数id，取比它小1的单数id的student
3、最后一个奇数id的student不用交换
```
SELECT s.id,t1.student FROM seat s	
LEFT JOIN(
	SELECT id,student FROM seat
	WHERE (id%2)=1
)t1 ON t1.id+1=s.id
WHERE t1.id IS NOT NULL
UNION	                            
SELECT s.id,t2.student FROM seat s
LEFT JOIN(
	SELECT id,student FROM seat
	WHERE (id%2)=0
)t2 ON t2.id-1=s.id
WHERE t2.id IS NOT NULL
UNION	                            
SELECT id,student FROM seat 
GROUP BY id,student
HAVING id IN(SELECT MAX(id) FROM seat) AND (id%2)=1
```