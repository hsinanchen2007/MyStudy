### 解题思路
此处撰写解题思路

### 代码

```mysql
select Email
from Person
group by Email
having count(Email) > 1
```

首先查找出表中的Email，然后将email进行分组，最后筛选找出email大于1（即重复）的值