```
SELECT ROUND(SQRT(MIN((POW(p1.x - p2.x, 2) + POW(p1.y - p2.y, 2)))),2) AS shortest
FROM point_2d AS p1
JOIN point_2d AS p2 
ON (p1.x, p1.y) <> (p2.x, p2.y)
```
思路还是大致一样的，区别在于过滤条件的书写