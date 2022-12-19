看了别人的答案总结了两种方法。
**方法一：连结两个表，性别相同，左表日期大于等于右表日期**
对性别相同，该天以及该天之前的所有日期的分数求和。
```
SELECT s1.gender, s1.day, SUM(s2.score_points) total
FROM Scores s1, Scores s2
WHERE s1.gender = s2.gender AND s1.day >= s2.day
GROUP BY s1.gender, s1.day
ORDER BY s1.gender, s1.day
```

**方法二：新增两个变量**
1.先按gender, day排序
```
SELECT gender, day
FROM Scores
ORDER BY gender, day
```
2.增加两个变量：
第一个变量@total用来记录累计分数；
第二个变量@pre_gender用来记录前一条记录的性别。
如果性别与前一条记录的性别一样，分数累加；如果性别与前一条记录的性别不一样，分数重置。
```
SELECT gender, day, 
       CASE WHEN @pre_gender = gender THEN @total := @total + score_points
            ELSE @total := score_points
       END AS total,   
       @pre_gender := gender
FROM Scores,
(SELECT @total := 0, @pre_gender := NULL) as init
ORDER BY gender, day
```
3.上面得到的这个表作为新表need，返回gender, day, total
```
SELECT gender, day, total
FROM (SELECT gender, day, 
            CASE WHEN @pre_gender = gender THEN @total := @total + score_points
                 ELSE @total := score_points
                 END AS total,   
            @pre_gender := gender
      FROM Scores,
      (SELECT @total := 0, @pre_gender := NULL) as init
      ORDER BY gender, day) AS need
```


