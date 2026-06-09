### 解题思路
此处撰写解题思路
	思路：
		1.倒序DESC,最大在上面
		2.用Scores a和Scores b,复刻Scores的内容(生成2个从大->小的倒序Scores)。
		3.创建a.Score和b.Score用于对比的变量。
		4.此处选择用b.Score比较a.Score,那么b就需要加入Distinct来'去重'.(这样可以通过'倒序+去重'让b.Score的每一行即为Rank值。但b.Score是完整版a.Score的缩略,需要通过对比来完善重合的Rank)
		5.通过count()来获取每一个rank值。(因为a,b中的value都是大->小,筛选出来b>=a的数量即为b的行数)

		(PS:count(column_name) : 返回指定列的值的数目)
		(PS:count(DISTINCT column_name) 函数返回指定列的不同值的数目)

		缺点：N x Distinct(n) 的比较,实际上可以画成一个array[N][n],只有包含含对角线的一半面积的遍历是有效遍历。命中率约为(n/2)/m %不到

### 代码

```mysql
select a.Score as score,
	(select count(distinct b.Score) from Scores b 
		where b.Score >= a.Score) as rank
from Scores a
order by score DESC
```