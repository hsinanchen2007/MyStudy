[**leetcode 数据库题目全部题解**](https://leetcode-cn.com/circle/article/vGr1Mc/)

# 解法一
父节点为NULL是根节点。
```
T.p_id is NULL
```
在父节点中出现过的是内部节点。
```
exists (
            select *
            from tree as T1
            where T1.p_id = T.id
)
```
其它的是叶子节点。

合并上述逻辑得：
```
select T.id,
if(T.p_id is NULL,
   'Root'
   ,
   if(
        exists (
            select *
            from tree as T1
            where T1.p_id = T.id
        )
       ,
       'Inner'
       ,
       'Leaf'
   ) 
  )as 'Type'
from tree as T
```
# 解法二
从id集合中，逐步排除掉根节点，叶节点，剩下的都是内节点。

考虑表left join自连接。
```
SELECT *
FROM tree AS T1 LEFT JOIN tree AS T2 ON (T1.id = T2.p_id)
显然T1.p_id为NULL的是根节点。
```
叶子节点的id不可能出现在p_id字段。因此T.p_id为NULL的是叶子节点。

剩下的是内节点。

合起来，判断节点类型的逻辑为：
```
if(T1.p_id IS NULL,
	'Root',
	if(T2.p_id IS NULL,
	'Leaf',
	'Inner'
	)
	) AS `Type`
```
完整的逻辑为：
```
SELECT distinct T1.id,
if(T1.p_id IS NULL,
	'Root',
	if(T2.p_id IS NULL,
	'Leaf',
	'Inner'
	)
	) AS `Type`
FROM tree AS T1 LEFT JOIN tree AS T2 ON (T1.id = T2.p_id)
```