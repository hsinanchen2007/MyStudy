
如果 n1.Number 为中位数，n1.Number（包含本身）前累计的数字应大于等于总数/2 同时n1.Number（不包含本身）前累计数字应小于等于总数/2


例如：0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3    共12个数 

     中位数0（包含本身）前累计的数字 7 >=6  0（不包含本身）前累计数字 0 <=6


例如：0，0，0，3，3，3     共6个数

     中位数0（包含本身）前累计的数字 3 >=3  0（不包含本身）前累计数字 0 <=3
                     
     中位数3（包含本身）前累计的数字 6 >=3  3（不包含本身）前累计数字 3 <=3
```
SELECT 
AVG(Number)median 
FROM
(SELECT n1.Number FROM Numbers n1 JOIN Numbers n2 ON n1.Number>=n2.Number 
 GROUP BY 
 n1.Number 
 HAVING 
 SUM(n2.Frequency)>=(SELECT SUM(Frequency) FROM Numbers)/2 
 AND 
 SUM(n2.Frequency)-AVG(n1.Frequency)<=(SELECT SUM(Frequency) FROM Numbers)/2
)s
```
