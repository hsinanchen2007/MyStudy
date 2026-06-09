基本用法：
UPDATE 表 SET
列 = CASE 列 WHEN 情况1 THEN 情况2 ELSE 情况3，最后要加上一个END；

还可以使用IF函数，和EXCEL函数一样的；

注意此时千万不能使用DECODE函数，decode函数针对不同的列，这里只有一列。

DECODE 语句与程序语言中的 IF THEN 语句类似 对于复杂的报表来说灵活性是
必需的 DECODE可以弥补标准的 SQL 与过程语言函数之间的缺陷
语法
DECODE(column1, value1, output1, value2, output2, output3)
语法中的例子是对 column1 列执行 DECODE 函数 如果 column1 有一个值为 value1
那么将会用 output1 来代替当前值 如果column1 的值为value2 那么就会用 OUTPUT2 来
代替当前值 如果 column1 中哪两个值都不是 那么就会用 OUTPUT3 来代替当前值


 UPDATE salary SET
sex =
  CASE sex WHEN 'm' THEN 'f' ELSE 'm' END
--     CASE WHEN salary.sex="f" THEN  "m" )


-- UPDATE salary 
-- SET
--   # sex =decode(sex,'m','f','m')  注意此处不能使用decode函数，
-- sex=IF(salary.sex="m","f","m")