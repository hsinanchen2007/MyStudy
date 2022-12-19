本题难点在于要显示某学生没参加过的考试的次数为0，需要理清楚三表之间的关系
- 建立表students和表subjects之间的笛卡尔积，这样就可以得到每个学生在所有科目下的情况
```
SELECT students JOIN subjects
```
- 利用examinations表得到每个学生参加过的科目的次数
```
SELECT *, COUNT(*) cnt
FROM examinations
GROUP BY student_id, subject_name
```
- 将上面得到的两张表连接起来就可以了，此处应当使用左连接
```
students t1 JOIN subjects t2
LEFT OUTER JOIN(
    SELECT *, COUNT(*) cnt
    FROM examinations
    GROUP BY student_id, subject_name) t3
```
最后对使用`IFNULL`函数处理cnt列
```
SELECT t1.student_id, 
    t1.student_name, 
    t2.subject_name,
    IFNULL(t3.cnt, 0) attended_exams
FROM
students t1 JOIN subjects t2
LEFT OUTER JOIN 
    (SELECT *, COUNT(*) cnt
    FROM examinations
    GROUP BY student_id, subject_name) t3
ON t1.student_id = t3.student_id
    AND t2.subject_name = t3.subject_name
ORDER BY t1.student_id, t2.subject_name
```







