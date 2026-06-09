### 解题思路
此处撰写解题思路

### 代码
# select if(id%2=0,id-1,if(id=(select max(id) from seat),id,id+1)) id,student from seat;
#仅这样id顺序不对 
```mysql
# Write your MySQL query statement below%2
select * from (select if(id%2=0,id-1,if(id=(select max(id) from seat),id,id+1)) id,student from seat) t order by id;
```