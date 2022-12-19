从Person中挑选出现超过一次的Email，通过Email分组
```sql
SELECT Email FROM Person 
GROUP BY Email
HAVING COUNT(Email) > 1
```
