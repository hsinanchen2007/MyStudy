起初的代码
```
SELECT t1.Id 
FROM Weather AS t1, Weather AS t2 
WHERE t1.Temperature>t2.Temperature 
AND 
DATEDIFF(t1.RecordDate, t2.RecordDate)=1;
```
![image.png](https://pic.leetcode-cn.com/302d6d484928d373d4ff5ada511a425cee819a58d78ab1f5afae24fd1976b45d-image.png)



```
SELECT t1.Id 
    FROM Weather AS t1, Weather AS t2 
        WHERE t1.Temperature>t2.Temperature 
        AND 
        DATEDIFF(t1.RecordDate, t2.RecordDate)=1;
```
![image.png](https://pic.leetcode-cn.com/2cbdf15ec296f7dfa260a4fa6a7dee9e362b8242d8294df9a5ac878ce7b616e1-image.png)

![image.png](https://pic.leetcode-cn.com/23154ed0bf2f3e0e39f6ee87fc3c9cfa897a865deb77683321cb3b08160d84c1-image.png)

![image.png](https://pic.leetcode-cn.com/187fb614c908e19b23492dbf4aae85fb7087dcdf0d94566e89a8c7edb47f15dd-image.png)

知识点总结：
**MySQL DATEDIFF() 函数**
语法
```
DATEDIFF(date1,date2)
```
**DATEDIFF() 函数返回两个日期之间的天数。**
date1 和 date2 参数是合法的日期或日期/时间表达式。

注释：只有值的日期部分参与计算。

**实例**
下面是 SELECT 语句：

```
SELECT DATEDIFF('2008-11-30','2008-11-29') AS DiffDate
```
结果如下所示：

DiffDate
1

```
SELECT a.Id
FROM weather a

LEFT JOIN weather b ON b.RecordDate = DATE_SUB(a.RecordDate,INTERVAL 1 DAY)
WHERE a.Temperature > b.Temperature

ORDER BY a.Id
```

也有老伙计用DATE_SUB的，似乎耗时更长一些

**定义和用法**
DATE_SUB() 函数从日期减去指定的时间间隔。

**语法**
DATE_SUB(date,INTERVAL expr type)
date 参数是合法的日期表达式。expr 参数是您希望添加的时间间隔。

**type 参数可以是下列值：**

**Type 值**
```
MICROSECOND
SECOND
MINUTE
HOUR
DAY
WEEK
MONTH
QUARTER
YEAR
SECOND_MICROSECOND
MINUTE_MICROSECOND
MINUTE_SECOND
HOUR_MICROSECOND
HOUR_SECOND
HOUR_MINUTE
DAY_MICROSECOND
DAY_SECOND
DAY_MINUTE
DAY_HOUR
YEAR_MONTH
```


**实例**
假设我们有如下的 "Orders" 表：

```
OrderId	ProductName	OrderDate
1	Jarlsberg Cheese	2008-11-11 13:23:44.657
```

现在，我们想要向 "OrderDate" 减去 5 天。

我们使用下面的 SELECT 语句：

```
SELECT OrderId,DATE_SUB(OrderDate,INTERVAL 5 DAY) AS SubtractDate
FROM Orders
```

**结果：**

OrderId	SubtractDate
1	2008-11-06 13:23:44.657







