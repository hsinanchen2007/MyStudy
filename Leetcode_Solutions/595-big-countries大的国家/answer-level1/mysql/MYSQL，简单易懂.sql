- 从world表选取要的数据name，populatio，area
- 条件为 area > 3000000 或者population > 25000000
```sql
SELECT name, population, area 
FROM WORLD
WHERE area > 3000000 OR population > 25000000;
```
