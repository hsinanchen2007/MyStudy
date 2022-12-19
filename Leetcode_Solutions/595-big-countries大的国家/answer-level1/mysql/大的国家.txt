### 解题思路
这题只有这么简单了（当然还可以用union，但效率更低）

### 代码

```mysql
select `name`,population,`area`
from World
where `area`>3000000 or population>25000000;
```