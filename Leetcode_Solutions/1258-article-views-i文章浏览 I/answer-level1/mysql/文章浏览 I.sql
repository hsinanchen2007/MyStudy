#### 方法一：`DISTINCT` 和 `ORDER BY`

**思路**

1. 题目要求**找出所有浏览过自己文章的作者**，很显然，这句话翻译过来就是 `author_id = viewer_id`。
2. 第一步已经筛选出所有的数据，但是有重复数据，需要继续处理。因为**此表无主键，因此可能会存在重复行**，所以我们要对结果去重，使用 `DISTINCT` 即可。
3. 最后使用 `ORDER BY` 将结果按照 `author_id` 升序排列。

**代码**

```Mysql [ ] 
SELECT DISTINCT author_id AS id
FROM  Views
WHERE author_id = viewer_id
ORDER BY author_id
```