设置sum_weight变量，按照turn排序，求出每个人上电梯后的总重量。最后取sum_weight 小于等于1000的，turn最大的人即可。

```
SELECT person_name 
FROM (SELECT person_name, turn, @sum_weight := @sum_weight + weight AS sum_weight 
FROM (SELECT person_name, turn, weight FROM queue ORDER BY turn)t1, (SELECT @sum_weight := 0)t2)t3
WHERE sum_weight <= 1000 
ORDER BY turn DESC 
LIMIT 1 
```
