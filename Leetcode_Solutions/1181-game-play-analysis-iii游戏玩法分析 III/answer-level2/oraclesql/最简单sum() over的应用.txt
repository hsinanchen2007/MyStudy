执行用时 :721 ms, 在所有 Oracle 提交中击败了100.00%的用户
select 
    player_id,
    to_char(event_date,'yyyy-mm-dd') event_date,
    sum(games_played) over(partition by player_id order by event_date) games_played_so_far 
from Activity