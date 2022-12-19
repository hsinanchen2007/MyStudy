### 解题思路
- 对trips表和users表连接，连接条件是用户且ID相同
- 筛选非禁止用户且日期在目标日期之间
- 用日期进行分组
- 分别统计所有订单数和被取消的订单数，其中取消订单数用一个sum嵌套IF语句来求解
- 对订单取消率保留两位小数，对输出列名改名

### 结果
![image.png](https://pic.leetcode-cn.com/a222817b0d946bd187262558f566a0fecd71fa6f844036a87a8892872ca5896a-image.png)

### 代码

```mysql
# Write your MySQL query statement below
SELECT
	request_at 'Day', round(SUM(Status!='completed')/COUNT(ID), 2) 'Cancellation Rate'
FROM 
	trips t JOIN users u ON (t.client_Id = u.users_id AND u.role = 'client')
WHERE	
	u.banned = 'No' and request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY 
	request_at
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)