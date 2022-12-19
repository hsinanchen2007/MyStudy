# Write your MySQL query statement below

SELECT avg(Number) as median
FROM
(
    SELECT Number,Frequency,
        @pre_num:=Number,
        @rank_down:=@rank_up as rank_down,
        @rank_up:=@rank_down+Frequency  as rank_up  
    FROM
    Numbers n, (SELECT @pre_num:=0,@rank_down:=0,@rank_up:=0) t
    ORDER BY Number
) A
,
(

    SELECT CEIL(SUM(Frequency)/2) as beg, IF(SUM(Frequency) mod 2=0,1,0) as cnt
    FROM Numbers
) B 
WHERE A.rank_up >=B.beg and A.rank_down <B.beg+B.cnt