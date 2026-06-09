
SELECT 
    id,CASE WHEN p_id IS NULL THEN 'Root' WHEN id NOT IN (SELECT p_id FROM tree WHERE p_id IS NOT NULL) THEN 'Leaf' ELSE 'Inner' END AS Type
FROM tree




SELECT
    id,IF(p_id IS NULL,'Root',IF(id NOT IN (SELECT p_id FROM tree WHERE p_id IS NOT NULL),'Leaf','Inner')) AS Type
FROM tree


注意:not in相当于all，如果 not in 后面跟的是子查询，子查询中只要包含一个 null 的返回值，则会造成 整个 not in 字句返回空值，查询不会返回任何结果。但in 相当于 any ,可以处理子查询中返回null的情况,返回正确的结果。
解决方案:
为防止not in返回空值，可以在子查询的Where 语句后筛掉为空的记录