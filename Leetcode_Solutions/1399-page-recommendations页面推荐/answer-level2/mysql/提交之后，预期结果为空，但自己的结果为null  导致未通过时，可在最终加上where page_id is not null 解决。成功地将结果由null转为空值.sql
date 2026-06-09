select r2.page_id as recommended_page
 from (
    select distinct page_id 
    from (
     select user2_id as id  from Friendship where user1_id='1'
union all 
     select user1_id as id from Friendship where user2_id='1') as r1 
    left join Likes as t1 on r1.id=t1.user_id) as r2  
          where r2.page_id not in (select page_id
                                     from Likes where user_id='1') 
           and r2.page_id is not null