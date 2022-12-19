select F1.followee follower,count(distinct F1.follower) num
from follow F1
where F1.followee in (select follower from follow)
group by F1.followee
