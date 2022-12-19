```
Select Round(Count(Distinct B.player_id)/Count(Distinct A.player_id),2) As Fraction
From (Select player_id,Min(event_date) As FirstDate From Activity Group By player_id) As A
Left Join Activity As B
On A.player_id=B.player_id And A.FirstDate+1=B.event_date
```