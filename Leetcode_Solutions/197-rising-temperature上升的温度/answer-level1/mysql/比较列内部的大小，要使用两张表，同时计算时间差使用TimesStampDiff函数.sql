因为比较的是一张表里边两行之间的关系，所以一定要使用两张表。

解法1,万能的TimesSatmpDiff函数，计算两个日期函数的差值，day，hour，second都可以：
SELECT 
    w2.Id AS Id
FROM Weather AS w1，Weather AS w2

WHERE 
     TIMESSTAMPDIFF(DAY,W1.RecordDate,W2.RecordDate) = 1  --逐行比较，此处w2的日期要比w1大
   AND W2.Temperature > W1.Temperature                    --同时满足W2温度高于w1