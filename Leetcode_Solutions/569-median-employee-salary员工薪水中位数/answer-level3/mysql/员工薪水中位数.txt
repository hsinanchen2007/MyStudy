#### 方法一： 利用 *中位数* 的定义 【通过】

**思路**

对于一个 *奇数* 长度数组中的 *中位数*，大于这个数的数值个数等于小于这个数的数值个数。

**算法**

根据上述的定义，我们来找一下 `[1, 3, 2]` 中的中位数。首先 `1` 不是中位数，因为这个数组有三个元素，却有两个元素 `(3，2)` 大于 `1`。`3` 也不是中位数，因为有两个元素小于 `3`。对于最后一个 `2` 来说，大于 `2` 和 小于 `2` 的元素数量是相等的，因此 2 是当前数组的中位数。

当数组长度为 *偶数*，且元素唯一时，中位数等于排序后 *中间两个数* 的平均值。对这两个数来说，大于当前数的数值个数跟小于当前数的数值个数绝对值之差为 1，恰好等于这个数出现的频率。

总的来说，不管是数组长度是奇是偶，也不管元素是不是唯一，中位数出现的频率一定大于等于大于它的数和小于它的数的绝对值之差。这个规律是这道题的关键，可以通过下面这个搜索条件来过滤。

```sql [snippet-MySQL]
SUM(CASE
    WHEN Employee.Salary = alias.Salary THEN 1
    ELSE 0
END) >= ABS(SUM(SIGN(Employee.Salary - alias.Salary)))
```

根据上述的搜索条件，可以轻松写出下面的 MySQL 代码。

**MySQL**

```sql [solution1-MySQL]
SELECT
    Employee.Id, Employee.Company, Employee.Salary
FROM
    Employee,
    Employee alias
WHERE
    Employee.Company = alias.Company
GROUP BY Employee.Company , Employee.Salary
HAVING SUM(CASE
    WHEN Employee.Salary = alias.Salary THEN 1
    ELSE 0
END) >= ABS(SUM(SIGN(Employee.Salary - alias.Salary)))
ORDER BY Employee.Id
;
```

> 注意：在 MySQL 5.6 中，这个代码是可以运行的，但如果你用的是 MySQL 5.7+，就需要在 SELECT 语句中 把 `Employee.id` 改成 `ANY_VALUE(Employee.Id)`。 

#### 方法二： 排序后再找 *中位数* 【通过】

**思路**

如果记录本身就是根据 **salary** 来排名的，那么很容易就能找到 *中位数*。但 MySQL 本身是没有内置的排名方法的，所以这里会有一些东西需要处理。

**算法**

根据 **salary** 排序记录，利用会话变量计算排名。由于不需要级联表，这个方法要比方法一更高效。

```sql [solution1-MySQL]
SELECT 
    Id, Company, Salary
FROM
    (SELECT 
        e.Id,
        e.Salary,
        e.Company,
        IF(@prev = e.Company, @Rank:=@Rank + 1, @Rank:=1) AS rank,
        @prev:=e.Company
    FROM
        Employee e, (SELECT @Rank:=0, @prev:=0) AS temp
    ORDER BY e.Company , e.Salary , e.Id) Ranking
        INNER JOIN
    (SELECT 
        COUNT(*) AS totalcount, Company AS name
    FROM
        Employee e2
    GROUP BY e2.Company) companycount ON companycount.name = Ranking.Company
WHERE
    Rank = FLOOR((totalcount + 1) / 2)
        OR Rank = FLOOR((totalcount + 2) / 2)
;
```