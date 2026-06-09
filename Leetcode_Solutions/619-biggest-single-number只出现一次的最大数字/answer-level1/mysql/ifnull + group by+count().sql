SELECT ifnull(max(num),null) as num 
FROM (SELECT num,count(num) FROM my_numbers GROUP BY num HAVING count(num)=1)t;