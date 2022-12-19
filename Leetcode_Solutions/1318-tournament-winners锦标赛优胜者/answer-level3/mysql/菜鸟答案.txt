```
select
	a.group_id as group_id,
	min(b.player) as player_id  
from
	(select
	p1.group_id,
	max(sum_score) as max_score
from
	Players p1 join (select
 	t.player as player,
 	sum(t.score) as sum_score
from
	(select
	first_player as player,
	sum(first_score) as score
from
	Matches
group by first_player

union all
select
	second_player as player,
	sum(second_score) as score
from
	Matches
group by second_player
) t
group  by t.player) t2  on p1.player_id=t2.player
group by p1.group_id) a join (select
	c.player,
	c.sum_score,
	p.group_id
from
	(select
 	t.player as player,
 	sum(t.score) as sum_score
from
	(select
	first_player as player,
	sum(first_score) as score
from
	Matches
group by first_player

union all
select
	second_player as player,
	sum(second_score) as score
from
	Matches
group by second_player
) t
group  by t.player) c join Players p on c.player=p.player_id) b on a.max_score=b.sum_score and a.group_id=b.group_id
group by a.group_id


```
