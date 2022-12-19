### 解题思路
此处撰写解题思路
1、读题-交换座位 case when 奇数偶数 % id交换优秀
2、多角度-最后一位为奇数时特殊处理
3、学习-mssql没看到特别的优化。mysql有if函数和mod函数。。。
### 代码

```mssql
SELECT  CASE WHEN id % 2 = 0 THEN id - 1
             WHEN id = ( SELECT MAX(id)
                         FROM   seat
                       ) THEN id
             ELSE id + 1
        END AS id ,
        student
FROM    seat
ORDER BY id;
```