上升的温度

### 函数DATEDIFF函数来计算两个日期值之间的天数。
### JOIN 关键字在用于内连接时，条件语句使用on，而不是where。
```sql
SELECT
    weather.id AS 'Id'
FROM
    weather
        JOIN
    weather w ON DATEDIFF(weather.RecordDate, w.RecordDate) = 1
        AND weather.Temperature > w.Temperature
;

```