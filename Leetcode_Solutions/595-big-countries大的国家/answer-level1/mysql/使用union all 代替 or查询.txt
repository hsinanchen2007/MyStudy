使用UNION ALL 代替 OR查询，效果还是可以的

`select distinct(t.name),t.population,t.area from
(
select name,population,area from World where area > 3000000 
UNION ALL
select name,population,area from World where population > 25000000
) as t `
实现结果：
![image.png](https://pic.leetcode-cn.com/6961b4a84d6ed0110fec354e62093a4e52adba2cfcc54241a6d6926c499567ae-image.png)
