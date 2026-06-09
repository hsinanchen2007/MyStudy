#### 预备知识

本题使用到的 `MySQL` 函数的说明：
- `ROUND(x, d)`： 四舍五入保留 `x` 的 `d` 位小数。

#### 方法一：直接计算

**思路**

题目要求**获取即时订单所占的比例**，最直观的思路就是计算出即时订单的数量，再计算出总订单的数量。即时订单数量除以总订单数据就是我们要求的比例。

**算法**

1. 计算即时订单数，即时订单的要求为**配送日期和下单日期相同**：
```Mysql [ ]
select count(*) from Delivery where order_date = customer_pref_delivery_date
```
2. 计算总订单数：
```Mysql [ ]
select count(*) from Delivery
```
3. 将两数相除，使用 `round` 函数保留 2 位小数，因为要计算的是所占比例，所以还需要乘 100。

**代码**

```Mysql [ ]
select round (
    (select count(*) from Delivery where order_date = customer_pref_delivery_date) / 
    (select count(*) from Delivery) * 100,
    2
) as immediate_percentage
```

#### 方法二： `sum` 和 `case when`

**思路**

我们可以使用 `sum` 和 `case when` 计算出即时订单的数量。当满足条件的时候，使用 `case when` 将 `sum` 值加 1。

**代码**

```Mysql [ ]
select round (
    sum(case when order_date = customer_pref_delivery_date then 1 else 0 end) /
    count(*) * 100,
    2
) as immediate_percentage
from Delivery
```

#### 方法三： `sum`

**思路**

我们还可以直接使用 `sum`。当 `order_date = customer_pref_delivery_date` 为真时，`sum` 值加 1。

**代码**

```Mysql [ ]
select round (
    sum(order_date = customer_pref_delivery_date) /
    count(*) * 100,
    2
) as immediate_percentage
from Delivery
```