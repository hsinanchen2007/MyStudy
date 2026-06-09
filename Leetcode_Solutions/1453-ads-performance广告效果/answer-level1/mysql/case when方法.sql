SELECT ad_id, iF(AVG(stat) is NULL,0.00,ROUND(AVG(stat)*100,2)) AS ctr
FROM
(SELECT ad_id,
CASE WHEN action='Clicked' Then 1
WHEN action='Viewed' THEN 0
ELSE NULL END AS stat
FROM Ads) AS sub
GROUP BY ad_id 
ORDER BY ctr DESC,ad_id

先将Ignored的部分变为Null,统计平均值时不会统计进去；
如果该ad_id全部为Ignored，就将NULL替换为0.00