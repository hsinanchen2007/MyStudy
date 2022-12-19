### 解题思路
直接全部来一遍，0即排除了重复点，但是这精度有问题啊
![微信图片_20200315184414.png](https://pic.leetcode-cn.com/1ddd598278630e77eebd5c7feee7cccd21e1819504b09f3e31d9098d7ecc4ff3-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200315184414.png)

### 代码

```mysql
# Write your MySQL query statement below
select
    round(sqrt(min(tmp.dis)), 2) shortest
from
    (
    select
        (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y) dis
    from
        point_2d                p1
            cross join point_2d p2
    ) tmp
where
    tmp.dis != 0
```