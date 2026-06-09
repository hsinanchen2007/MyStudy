定义两个变量@num，@id。@id用来存放log_id，@num用来标记log_id连续的记录。
```MySQL
SELECT
	log_id,
	CASE WHEN @id = log_id - 1 
        THEN @num := @num
        ELSE @num := @num + 1
        END num,
        @id := log_id
FROM LOGS,
(SELECT @num := 0, @id := NULL) a
```

执行结果如图：
![111.png](https://pic.leetcode-cn.com/e82a7f73284a880deb639b606723f2d9cc76e8d76aba0d26d5b4b12c89337d0c-111.png)

得到上述结果后，用num字段分组，最小log_id为start_id，最大log_id为end_id。
```MySQL
SELECT
    min(log_id) start_id,
    max(log_id) end_id
FROM
	(
        SELECT
		log_id,
		CASE WHEN @id = log_id - 1 
                THEN @num := @num
		ELSE @num := @num + 1
		END num,
		@id := log_id
	FROM LOGS,
            (SELECT @num := 0, @id := NULL) a
	) x
GROUP BY
	num
```
