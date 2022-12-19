sql语句如下：
SELECT DISTINCT ConsecutiveNums
FROM (
	SELECT DISTINCT temp.ConsecutiveNums, temp.rn
	FROM (
		SELECT ConsecutiveNums, rn - rn2 AS rn
		FROM (
			SELECT l.Num AS ConsecutiveNums, 
			       row_number() OVER (ORDER BY l.id) AS rn, 
			       row_number() OVER (PARTITION BY l.Num ORDER BY l.id) AS rn2
			FROM Logs l
		)
	) temp
	GROUP BY temp.ConsecutiveNums, temp.rn
	HAVING COUNT(*) >= 3
)
看了官方的解答，但是感觉应该还有其他的方法吧，万一要求连续出现10次的数字，那不得写死啊，但是，我自己是没想出来咋整，去百度了下，参考别人的思路写了一下，但是我还是感觉有问题，当ID不是按顺序排列时，这个SQL应该是错误的，这应该只能用在ID是按顺序排列的数据中；
1.row_number() OVER (PARTITION BY l.Num ORDER BY l.id) AS rn2
这句sql的作用是将数据根据NUM进行分组，然后再在各个组中根据ID进行排序。也就是说先将一样的NUM都分到了同一组。并且获得新的序号rn2
2.row_number() OVER (ORDER BY l.id) AS rn
将语句1里的结果根据ID进行排序，将因为语句1而分在同一组中，连续挨着的数据，恢复到原先的顺序。并且获得新的序号rn
3.rn - rn2 AS rn
这是关键，rn-r2,rn是根据id进行排序，所以，rn应该是一组连续出现的数字，例如 1,2,3,4,5,6,7,8,9,10
而rn2是先根据NUM进行分组，然后再在组里根据ID进行排序的数字，例如-----------1,2,3,1,2,1,1,1,2,3
相减的结果-------------------------------------------------------------0,0,0,3,3,5,6,7,7,7
结果中连续出现3次相同的数字即代表NUM连续出现3次
最后distinct ConsecutiveNums 就是最后的结果。
