SELECT
	e.NAME,
	b.bonus
FROM
	employee e
-- 使用on 过滤条件可以在右边的empId为null 时仍然显示左表的数据, 但是bonus 为null 则不显示, 所以在where 中添加b.bonus避免bonus weinull 是不显示左表的数据.
LEFT JOIN bonus b on e.empId = b.empId
WHERE
	b.bonus < 1000 or b.bonus is null;