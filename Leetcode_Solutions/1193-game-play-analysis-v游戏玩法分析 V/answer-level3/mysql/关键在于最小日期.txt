### 解题思路
首先获取每个用户最小的开始游戏日期，然后联表直接定位到每一位用户的下一天的那条数据上,输出就可以了

### 代码

```mysql
# Write your MySQL query statement below



select a.m_date as install_dt,count(a.player_id) as installs,round(count(b.player_id)/count(a.player_id),2) as Day1_retention from (select player_id,min(event_date) m_date from Activity group by player_id) a left join Activity b on a.player_id = b.player_id and datediff(b.event_date,a.m_date) =1  group by a.m_date;





```