### 解题思路
这里首先先解释一下题目，因为我看的是英文版，可能更好理解一些。首先 这个表里有两列，sub_id 和 parent_id，分别记录了 帖子或者评论的信息。如果这一行表示的是发布帖子，那么他的 parent_id 就会为 null。因为帖子自己本身就是一个 母类。而如果这一行记录的是帖子的回复，那么他就会有对应的 parent_id。这时候，这一行对应的 sub_id 就是 这条回复的id，而parent_id对应的是这条回复所在的帖子。

所以，我们可以先建立临时表 t，t返回的是帖子的id。这样的话将原表格和临时表右连接，保留右表的内容，因为我们需要根据右边表格返回的sub_id （这里是表示帖子的id）来进行group by分组，最后别忘记对 左表的 回复 去重以及处理空值。 

### 代码

```mysql
# Write your MySQL query statement below

select t.sub_id as post_id, ifnull(count(distinct s.sub_id),0) as number_of_comments
from submissions s
right join 
(
select sub_id
from submissions
where parent_id is null
) t
on s.parent_id = t.sub_id
group by t.sub_id;
```