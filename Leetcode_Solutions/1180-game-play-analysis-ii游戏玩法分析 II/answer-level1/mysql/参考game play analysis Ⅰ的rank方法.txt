```
SELECT tmp.player_id, tmp.device_id
FROM (select player_id, device_id, RANK() OVER(PARTITION BY player_id ORDER BY event_date) AS r 
	    FROM activity) AS tmp
WHERE r=1
```
网站的mysql似乎不是8.0不支持rank，可以自己写一个
```
SELECT tmp.player_id, tmp.device_id
FROM (select player_id, device_id, RANK() OVER(PARTITION BY player_id ORDER BY event_date) AS r 
	    FROM activity) AS tmp
WHERE r=1
```

```
SELECT tmp.player_id, tmp.device_id
FROM (select player_id, device_id, 
        (SELECT COUNT(player_id)+1 
            FROM activity AS a2
            WHERE a1.player_id=a2.player_id AND a1.event_date>a2.event_date) AS r 
	    FROM activity a1) AS tmp
WHERE r=1
```
但是这种方法速度很慢，leetcode不会通过...仅提供思路

