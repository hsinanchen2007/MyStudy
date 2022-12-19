### 解题思路
-- 这是一个函数，就相当于代码里面声明一个方法一样，(N INT) -> 声明类型，(RETURNS INT) -> 返回值为int类型，可以存在多个
-- N = 第几名的意思，传过来的值就不能是0或者负数的，所以先判断是否小于1
-- 到达查询的部分，与上一题的解题思路是一样的，直接带入，将limit 1 改成 limit N 就好了
	-- 首先将数据进行去重，然后按照从大到小的顺序进行排序，最后出数的时候，进行出数控制就行了
	-- 通俗一点讲，limit代表是第几页(下标从0开始)，offset代表这一页显示多少个数据，我们只需要一个数输出(offset=1)，需要第几名就是(N-1)了

### 代码

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  IF N < 1 THEN
	RETURN NULL;

ELSE

SET N = N - 1;

RETURN (
  -- 只要offset为1(只显示一个)，那么N则作为页数
	SELECT
		IFNULL(
			(
				SELECT DISTINCT
					(salary)
				FROM
					employee
				ORDER BY
					salary DESC
				LIMIT N,
				1
			),
			NULL
		)
);

-- RETURN  == return 的意思
END
IF;
END
```