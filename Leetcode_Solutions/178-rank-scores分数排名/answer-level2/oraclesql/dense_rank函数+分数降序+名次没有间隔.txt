 select  Score,
		 dense_rank() over(order by score desc)  as Rank
 from  Scores  
 order by  Scores desc;