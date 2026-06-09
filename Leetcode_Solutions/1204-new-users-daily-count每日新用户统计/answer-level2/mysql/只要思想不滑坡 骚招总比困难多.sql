### 解题思路
只要思想不滑坡 骚招总比困难多。。。
做了一个临时的数据集，然后二次过滤 美滋滋
### 代码

```mysql

select first_login as login_date,count(user_id) as user_count  from (select user_id,min(activity_date) as first_login  from Traffic where activity = 'login'  group by user_id having datediff('2019-06-30',first_login) <= 90) a group by first_login order by first_login asc




```