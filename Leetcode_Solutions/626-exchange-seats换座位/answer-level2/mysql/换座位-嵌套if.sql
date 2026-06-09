### 解题思路
if嵌套：
若id为偶数，id-1
若id为奇数，内嵌一个if：且id等于总数，id不变，否则id+1

### 代码

```mysql
# Write your MySQL query statement below
select 
if(mod(id,2)=0,id-1,if(
        id=(select count(*) from seat), id, id+1
    )
)as id, student
from seat
order by id

```