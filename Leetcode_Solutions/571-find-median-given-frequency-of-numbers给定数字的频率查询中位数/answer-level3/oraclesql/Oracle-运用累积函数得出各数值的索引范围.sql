**题目中关于中位数的定义（取法）：**
1. 若数列元素个数为奇数个，则取最中间的数；
2. 若数列元素个数为偶数个，则取最中间的两个数，然后求这两个数的平均数（均值）。

**这里还有一个推论：**
对于任一数列而言，若我们将其中所有数值出现的频率翻倍（*2），其中位数的值将保持不变（与翻倍前的中位数值相同）。

因此，我们只需要将所有数值出现的频率翻倍，便可保证新数列的中位数的解法一定是 取中间**两位数字**并求其平均值。

假设数列为 **Array**，数列元素总个数（总频率）为 **total_freq**，则中位数为：
```
medians = avg(Array[total_freq/2], Array[total_freq/2+1])
```


运用 oracle 窗口函数中的求和函数来计算各个 number 的 frequency 的累积值，以此来推算各 number 在数列中的下标（索引）范围（执行下述SQL语句）：
```sql
with accu_freq_rpt as( -- 频率*2，可保证中位数均为两个数字
		select "Number",
			sum(frequency*2) over(order by "Number") as accu_freq, -- 累积频率
			sum(frequency*2) over() as total_freq -- 总频率
		from numbers
		),
	num_idx_rpt as (
		select "Number",
			lag(accu_freq, 1, 0) over(order by "Number") + 1 as start_idx,
			accu_freq as end_idx,
			total_freq
		from accu_freq_rpt
		)

select * from num_idx_rpt
```

SQL执行结果如下表所示，各 number 在数列中的索引范围为 **[start_idx, end_idx]**。
比如，0的索引范围为 [1,14]，1的索引范围为[15,16]。
| number | start_idx（索引范围起始值） | end_idx（索引范围结束值） | 索引范围 | total_freq |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 1 | 14 | 1~14 | 24 |
| 1 | 15 | 16 | 15~16 | 24 |
| 2 | 17 | 22 | 17~22 | 24 |
| 3 | 23 | 24 | 23~24 | 24 |


再来分析一下最终取得的两位中位数的分布情况，共有两种：
1. 两位中位数值相同；此时，两位中位数的索引（下标）在同一个索引范围内。换句话说，两个索引落在上表的同一行内。
2. 两位中位数值不相同；此时，两位中位数的索引（下标）分别位于两个索引范围内。换句话说，两个索引分别位于上表的不同行内（跨两个行），且分别对应于两个不同索引范围区间的头和尾。


综上，可得出最终SQL为：
```sql
with accu_freq_rpt as( -- 频率*2，可保证中位数均为两个数字
		select "Number",
			sum(frequency*2) over(order by "Number") as accu_freq, -- 累积频率
			sum(frequency*2) over() as total_freq -- 总频率
		from numbers
		),
	num_idx_rpt as (
		select "Number",
			lag(accu_freq, 1, 0) over(order by "Number") + 1 as start_idx,
			accu_freq as end_idx,
			total_freq
		from accu_freq_rpt
		)

select
	cast(avg("Number") as decimal(10, 2)) as medians -- 两个中位数，求均值，即可得题目中要求的中位数
from num_idx_rpt
where
	(start_idx <= total_freq/2 and total_freq/2+1 <= end_idx) -- 在一行内
	or
	(end_idx = total_freq/2 or start_idx = total_freq/2+1) -- 跨两个行
```
