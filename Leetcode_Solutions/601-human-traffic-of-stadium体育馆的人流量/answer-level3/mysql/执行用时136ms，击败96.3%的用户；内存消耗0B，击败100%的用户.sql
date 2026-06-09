### 结果
![屏幕快照 2019-12-15 23.19.32.png](https://pic.leetcode-cn.com/c622d2e079a53e3f39222e51f5997268278f4753cc04babb4650a0f75cc6284e-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-15%2023.19.32.png)

### 解题思路
1.先用查询算出连续不小于 100 出现的统计，记为countt（小于 100 的值为0，不小于的值在上一次的基础上加一）。
2.对第1步的结果增加一个标记位flag，倒叙看countt，不小于3或上一flag为1，并且countt不等于0的，标记flag为1
3.对第2步的结构查询，找出flag为1的就好，排序倒回来

简单点来说就是就是加了两列用来做标记，先用一列来算连续出现的情况，针对新加的上一列倒过来再算一个分组标记。

### 代码

```mysql
SELECT id, visit_date, people
FROM (
	SELECT r1.*, @flag := if((r1.countt >= 3 OR @flag = 1) AND r1.countt != 0, 1, 0) AS flag
	FROM (
		SELECT s.*, @count := if(s.people >= 100, @count + 1, 0) AS `countt`
		FROM stadium s, (SELECT @count := 0) b
	) r1, (SELECT @flag := 0) c
	ORDER BY id DESC
) result
WHERE flag = 1 ORDER BY id;
```

### 20200310 补充下假如是表格来处理的结果，更直观一些
![image.png](https://pic.leetcode-cn.com/1525cfc9730dec77371cc775a0a9d7bc42637ac852ae0b4f84cbdc378dab6f14-image.png)
