#### 方法 1：使用子查询和 `SUM()` 函数 [Accepted]

**想法**

计算每个问题的“回答次数除以出现次数”。

**算法**

首先，我们使用 `SUM()` 和子查询求得每个问题的回答次数和出现次数，如下：

```sql [-Sql]
SELECT
    question_id,
    SUM(CASE
        WHEN action = 'answer' THEN 1
        ELSE 0
    END) AS num_answer,
    SUM(CASE
        WHEN action = 'show' THEN 1
        ELSE 0
    END) AS num_show
FROM
    survey_log
GROUP BY question_id
;
```

```
| question_id | num_answer | num_show |
|-------------|------------|----------|
| 285         | 1          | 1        |
| 369         | 0          | 1        |
```

然后，我们利用回答率的定义来求得答案。

**MySQL**

```sql [-Sql]
SELECT question_id as survey_log
FROM
(
	SELECT question_id,
         SUM(case when action="answer" THEN 1 ELSE 0 END) as num_answer,
        SUM(case when action="show" THEN 1 ELSE 0 END) as num_show,    
	FROM survey_log
	GROUP BY question_id
) as tbl
ORDER BY (num_answer / num_show) DESC
LIMIT 1
```

#### 方法 2：使用子查询和 `COUNT(IF...)` 函数 [Accepted]

**算法**

这个方法非常直接：结合 `COUNT()` 函数和 `IF()` 函数来求得每个问题的回答次数和出现次数。

**MySQL**
```sql [-Sql]
SELECT 
    question_id AS 'survey_log'
FROM
    survey_log
GROUP BY question_id
ORDER BY COUNT(answer_id) / COUNT(IF(action = 'show', 1, 0)) DESC
LIMIT 1;
```