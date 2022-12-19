### 解题思路
首先考虑把等级先划分出来，按score去降序排序（因为相同分数是一样的等级，所以对分数进行去重），
用Oracle中的rownum直接就可以作为RANK等级了，再用关联查询，将原表的所有数据都带上等级即可。
其中要注意的一点，rownum是查询后给赋予的行标，所以要用子查询，先排序后取rownum;
关联查询哪边带加号这张表就是被关联的（取另一张表的全量）。

### 代码

```oraclesql
/* Write your PL/SQL query statement below */

select b.score ,a.rank from 
(select rownum as rank ,t.* from 
(select distinct(score) from Scores order by score desc) t) a , scores b where a.score(+) = b.score;
```