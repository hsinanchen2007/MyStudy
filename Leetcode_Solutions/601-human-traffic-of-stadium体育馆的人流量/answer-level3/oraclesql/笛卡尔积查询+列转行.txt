    with t as (
        select 
           s1.id id1,
           s2.id id2,
           s3.id id3,
           s1.people people1,
           s2.people people2 ,
           s3.people people3,
           s1.visit_date visit1,  
           s2.visit_date visit2,
           s3.visit_date visit3
        from stadium s1,stadium s2,stadium s3
        where  (s1.id - s2.id = 1 and  s2.id-s3.id=1)
           and (s1.people>=100 and s2.people>=100 and s3.people>=100)
    )   
    select
        distinct 
        decode(lvl, 1,  id1,  2,  id2,  3 , id3) as id,
        decode(lvl, 1,  people1,  2,  people2,  3 , people3) as people,
        to_char(decode(lvl, 1,  visit1,  2,  visit2,  3 , visit3),'yyyy-MM-dd') as VISIT_DATE
    from t, (select level lvl from dual connect by level <4) 
    order by id asc