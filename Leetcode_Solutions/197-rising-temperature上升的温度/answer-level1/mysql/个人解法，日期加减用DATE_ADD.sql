-- 77.06%
-- 被日期坑了下，之前我是直接用+号🤣
-- ```
SELECT w1.Id AS Id
FROM 
    Weather w1,
    Weather w2
WHERE 
    w1.RecordDate = DATE_ADD(w2.RecordDate, interval 1 day)
    AND w1.Temperature > w2.Temperature
-- ```
