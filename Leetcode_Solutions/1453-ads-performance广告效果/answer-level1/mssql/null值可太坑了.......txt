### 解题思路
脚本如下

### 代码

```mssql
/* Write your T-SQL query statement below */
select aaa.ad_id,
    case when isnull(t0.acp,0)+isnull(t1.avp,0) = 0 then 0 
    else cast(isnull(isnull(t0.acp*100.,0)/case when (isnull(t0.acp,0)+isnull(t1.avp,0)) = 0 then 1 else (isnull(t0.acp,0)+isnull(t1.avp,0)) end,0) as decimal(8,2)) end ctr from
(select distinct ad_id from ads) aaa
left join
(select ad_id,count(action) acp from Ads where action = 'Clicked' group by ad_id) t0
on aaa.ad_id = t0.ad_id
left join
(select ad_id,count(action) avp from Ads where action = 'Viewed' group by ad_id) t1
on aaa.ad_id = t1.ad_id
order by isnull(isnull(t0.acp*100.,0)/case when (isnull(t0.acp,0)+isnull(t1.avp,0)) = 0 then 1 else (isnull(t0.acp,0)+isnull(t1.avp,0)) end,0) desc,aaa.ad_id
```