SELECT w1.id
from Weather as W1
INNER JOIN Weather as W2
ON DATEDIFF(W1.RecordDate,W2.RecordDate) = 1
where W1.Temprature > W2.Temprature

##    当代码最后一句改成 W1.Temprature < W2.Temprature ,第一句改成 w2.id 时 结果为 {2}
## 这是因为 DATEDIFF(W1.RecordDate,W2.RecordDate) = 1 会把ID = 2 和 ID = 3 做比较 ，结果只有一个2.