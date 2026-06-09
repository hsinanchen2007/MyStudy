### 解题思路
此处撰写解题思路

### 代码

```mysql
# Write your MySQL query statement below
#SELECT  COUNT( DISTINCT T1.sender_id)/COUNT(DISTINCT  T2.accepter_id) AS accept_rate
#SELECT ROUND(IFNULL(count(t2.*)/count(t1.*),0),2)  AS accept_rate 
SELECT DISTINCT ROUND(IFNULL(NUM1/NUM2,0),2) AS accept_rate
FROM  
    (SELECT DISTINCT COUNT(DISTINCT requester_id,accepter_id) AS NUM1  FROM request_accepted) T2
,
    (SELECT DISTINCT COUNT(DISTINCT sender_id,send_to_id) AS NUM2  FROM friend_request) T1 

```