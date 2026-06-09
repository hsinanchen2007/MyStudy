### 解法一：使用union合并的解法
思路：

分为三部分：

1、找到根节点：

根节点只有一个。tree表中p_id为null的那个节点就是根节点。

2、找到内部节点：

tree表自关联，拿p_id列数据（要排除掉p_id列为null的数据，因为这是根节点。）去id列中匹配。
如果在id列中能找到匹配的，且匹配行的p_id不为null，那么就可以确定这个id是内部节点。

3、找到叶子节点：

使用排除法。找到tree表中有子节点的所有节点id，然后所有节点排除掉这些节点id，就可以找到叶子节点。
要注意一种特殊的情况，就是只有一个根节点的情况。这种情况下该节点没有子节点，会被当成叶子节点。
所以判断叶子节点时还要排除根节点，也就是排除p_id为null的节点。
```
select id,'Root' as Type from tree 
where p_id is null
union
select b.id,'Inner' as Type from tree a
left join tree b on a.p_id = b.id
where a.p_id is not null and b.p_id is not null
union 
select id,'Leaf' as Type from tree 
where id not in(
	select a.id from tree a
	inner join tree b on a.id = b.p_id
) and p_id is not null
order by id
```
执行用时 :666 ms, 内存消耗 :0B

### 解法二：使用case when解决（参考其他大神的解法）
思路：

使用条件判断，依次判断：

case1： 如果该节点的p_id为null，则为根节点；

case2： 如果该节点出现在p_id列，说明它有子节点，可能是内部节点，也可能是根节点。因为case1已经确定了根节点，所以这种节点只能是内部节点；

case3： 除了根节点和内部节点，剩余的就都是叶子节点了。
```
select id,
    case when p_id is null then 'Root'
    when id in(select distinct p_id from tree) then 'Inner'
    else 'Leaf' end as Type
from tree
order by id
```
执行用时 :645 ms, 内存消耗 :0B