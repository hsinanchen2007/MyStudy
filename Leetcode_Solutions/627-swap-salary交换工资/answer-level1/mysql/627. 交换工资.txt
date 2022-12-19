- Update Table
  Set 字段 = CASE 
       WHEN 条件 THEN 结果 ELSE 结果 END

- Update Table
  Set 字段 = CASE 
       WHEN 条件 THEN 结果 
       WHEN 条件 THEN 结果 
       END

```
# Write your MySQL query statement below

UPDATE salary
SET sex = CASE WHEN sex = 'm' THEN 'f'
    ELSE 'm'
    END
```

```
UPDATE salary
SET sex = CASE
    WHEN sex = 'm' THEN 'f'
    WHEN sex = 'f' THEN 'm'
    END
```
