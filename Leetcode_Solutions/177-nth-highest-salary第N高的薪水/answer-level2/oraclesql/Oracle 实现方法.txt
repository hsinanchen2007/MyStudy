# 解题思路
1.考虑 N<1 的情况；
  考虑 N>count(dinsctinct salary) 的情况。
2.用Oracle自带的**rownum**,oracle系统顺序分配为从查询返回的行的编号:注意（如果想找到从第二行记录以后的记录，当使用rownum>2是查不出记录的，原因是由于rownum是一个总是从1开始的伪列，Oracle 认为rownum> n(n>1的自然数)这种条件依旧不成立，所以查不到记录。）
**正确查找方式：（查找到第二行以后的记录可使用以下的子查询方法来解决）**

# 代码
```
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
        select nvl(salary,null) into result --NVL()函数可以解决salary不存在的情况
            from
                (select salary ,rownum as num 
                    from 
                        (select distinct salary from employee order by salary desc) --去除重复值，倒序排列
                            WHERE ROWNUM<=N --缩小查询结果，增加性能
                ) --子查询的方式,给rownum定义一个别名num，记录下来查询结果
                    where num = N;
        RETURN result;
 END;
```


另附温馨小技巧：力扣用Oracle写查询语句给字段取**别名**时，用 AS + **" 字段名称 "**  可以解决Oracle对于所有**运行结果全部转大写的问题**。