select a.day,round(sum(a.cancel)/count(a.cancel),2) 'Cancellation Rate'
from 
    (select 
        t1.request_at day,if(t1.status != 'completed',1,0) cancel
    from 
        trips t1 inner join users t2 
            on t1.client_id = t2.users_id
    where 
        request_at between  '2013-10-01' and '2013-10-03'
        and 
        t2.banned = 'no')a
    group by a.day


# 核心思想是新建列来记录是否取消，+上group操作
# 话说当别名中含有空格时一定要用''来框起，
**否则你瞪半个小时也不知道哪里错了。。**