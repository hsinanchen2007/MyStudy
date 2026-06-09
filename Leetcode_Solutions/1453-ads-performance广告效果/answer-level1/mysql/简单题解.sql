简单描述一下思路，用group by 对ad_id进行聚合，然后用if语句统计action为clicked的数量做分子，用if语句统计action 不为ignored的数量（就三种，不为ignored就是其他两个）的和做分母，用round函数取2位，而对于没有点击的广告，会出现null，这时候用ifnull来置0，以此解决。下面是代码
```
select ad_id,ifnull(round(sum(if(action='Clicked',1,0))/sum(if(action!='Ignored',1,0))*100,2),0) ctr
from Ads 
group by ad_id
order by ctr desc,ad_id
```
