我的写法 供大家参考 找出后面连续两天客流量都超过100的id，然后展示当天及后面两天
with tmp as 
(select a.id from stadium a
join stadium b on a.id=b.id-1
join stadium c on a.id=c.id-2
where a.people>=100
and b.people>=100
and c.people>=100)

select id,visit_date,people from stadium
where id in (select id from tmp)
or id-1 in (select id from tmp)
or id-2 in (select id from tmp)
