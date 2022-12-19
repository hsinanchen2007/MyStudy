*如有可优化的步骤还请各位大神斧正*
步骤1.在Traffic表中查询出activity值为login的数据，获得所有用户的登录信息。
```
SELECT 
    user_id, acticity, acticity_date
FROM
    Traffic
WHERE
    activity = 'login';
```
步骤2.因为步骤1获得的结果集可能存在多个重复的`user_id`，所以对结果集使用`user_id`进行分组，使用`MIN()`函数查找每个分组中最早（小）的`activity_date`，即为每个用户的首次登录日期。
```
SELECT 
    user_id, MIN(activity_date) AS login_date
FROM
    Traffic
WHERE
    activity = 'login'
GROUP BY user_id;
```
步骤3.题目中要求统计用户首次登录日期范围是包括2019年06月30日在内的共90天，使用`DATE_SUB()`函数对步骤2所得结果集进行筛选。
```
SELECT 
    user_id, MIN(activity_date) AS login_date
FROM
    Traffic
WHERE
    activity = 'login'
GROUP BY user_id
HAVING MIN(activity_date) BETWEEN DATE_SUB('2019-06-30', INTERVAL 90 DAY) AND '2019-06-30';
```
步骤4.最后将步骤3所得结果集使用`login_date`进行重新分组，使用`COUNT()`函数统计行数，即为每个日期该日期首次登录的用户数。
```
SELECT 
    login_date, COUNT(login_date) AS user_count
FROM
    (SELECT 
        user_id, MIN(activity_date) AS login_date
    FROM
        Traffic
    WHERE
        activity = 'login'
    GROUP BY user_id
    HAVING MIN(activity_date) BETWEEN DATE_SUB('2019-06-30', INTERVAL 90 DAY) AND '2019-06-30'
    ORDER BY activity_date , user_id) AS a
GROUP BY login_date;
```