>这一类题之后也遇到过！
>类似的关键词在**连续出现n次**

# 连续 n 次 一般解题思路
假设有表logs，问 n = 3 的时候 如何如何，比如连续出现3次的数字，或者连续3个大于10的数字等等，
此处就用连续出现3次的数字
1. 首先将logs搞出3个一样的表，l1, l2, l3 `select * from logs as l1, logs as l2, logs as l3`
2. 将`l1 left join l2 on l1.id + 1 = l2.id and l2.id + 1 = l3.id`三张表根据错开一位的逻辑左连接在一起，得到下图效果 （错开一位是为了使得同一行形成连续的id）
![image.png](https://pic.leetcode-cn.com/9fc48eb6208679662aab50797438aa98409ecfebf9cca5a1f8a2b3d632cb5c5e-image.png)
*图中被黄色圈出的部分则为符合题目要求的条目*
 
在“错位”组合之后，对于第一列id来说，每一行之后的两列id对应的数字，都是自己之后紧紧连续着的两个数字。
所以，对于某一行，三列的数字都相同，则这个数字符合题目要求
**SQL：**
```
select distinct l1.num as ConsecutiveNums
from logs as l1 left join logs as l2 on l1.id = l2.id - 1
left join logs as l3 on l1.id = l3.id - 2
where l1.num = l2.num and l1.num = l3.num
```
**需要注意的是：**
1. 对select的对象加distinct，因为如果某数字连续出现3次，之后又出现了3次，或者连续出现3次以上，都会导致select l1.num多次输出相同的数字，而我们只需要一次而已。
2. 关于where的筛选：要注意一个错误写法，我自己就踩雷了：
`l1.num = l2.num = l3.num `
上述code并不是3连等，而是`(l1.num = l2.num) = l3.num`
即：先判断l1.num = l2.num 是否为真，括号内判断之后会返回一个bool value，为真返回1，为假返回0
之后再用l3.num与0或1进行比较。所以不能这么写

*******
一些其他小修改的发散
本解题思路用的是左连接
当然也可以用笛卡尔乘积，之后在where里进行限定
不过据我了解笛卡尔乘积的运算效率貌似是不如直接左连接的

