### 解题思路
不管person有无address都返回，那就是以person表为主，可以使用left join 或right join，只要主表是person表就OK，如果使用where的话，只返回条件存在的。

### 代码

```mysql
# Write your MySQL query statement below
SELECT P.FirstName,P.LastName,A.City,A.State FROM PERSON P LEFT JOIN Address A ON P.PERSONID=A.PERSONID;
```