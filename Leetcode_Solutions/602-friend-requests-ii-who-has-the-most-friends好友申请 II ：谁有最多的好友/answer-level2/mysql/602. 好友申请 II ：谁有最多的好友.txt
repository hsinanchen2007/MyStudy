1. 添加好友行为是双方的，requester_id 也是 accepter_id，union整合并去重
```
    select distinct 
        requester_id as id,
        accepter_id as cid 
    from 
        request_accepted 
    union
        select 
            accepter_id as requester_id,
            requester_id as accepter_id
        from 
            request_accepted
```

2. 对1的结果group requester_id，按照accepter_id个数排序取第一个即可
```
select id,count(1) as num
from (
    select distinct 
        requester_id as id,
        accepter_id as cid 
    from 
        request_accepted 
    union
        select 
            accepter_id as requester_id,
            requester_id as accepter_id
        from 
            request_accepted
) temp
group by id
order by num  desc
limit 0,1
```