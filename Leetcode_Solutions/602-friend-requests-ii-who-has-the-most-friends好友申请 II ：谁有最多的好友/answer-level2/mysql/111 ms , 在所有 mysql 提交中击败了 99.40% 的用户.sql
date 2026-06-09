```
# 直接使用别名, 比官方少了一次包装.
select requester_id id, count(*) num from (
    select requester_id from request_accepted
-- 使用union 会删除重复的requester, 不能得到实际的数量
    union all
    select accepter_id from request_accepted
) t 
group by requester_id 
order by num desc 
limit 1;
```