## 思路

1. 分析本题，让查找至少有5名直接下属的经理，并打印他的名字；
2. 我们观察Employee表的组成，会发现只要根据ManagerId分组，然后having过滤出5个及以上的非空ManagerId，就可以找到符合条件的经理的Id；
3. 后面通过Id,获取名字就有各种不同的方法了，比如in+子查询，或者自连接join等，输出Name即可

## 结论

1. 根据ManagerId分组，并用having过滤非空且出现5次及以上的ManagerId，即为符合条件的经理Id；

    ```sql 
    select ManagerId from Employee e group by ManagerId having ManagerId !='null' and count(ManagerId)>=5
    ```

2. in + 子查询，或者join自连接，输出Name

   - 方法1
  
    ```sql
        --in + 子查询
        SELECT
            NAME
        FROM
            Employee
        WHERE
            Id IN (
                SELECT
                    ManagerId
                FROM
                    Employee e
                GROUP BY
                    ManagerId
                HAVING
                    ManagerId != 'null'
                AND count(ManagerId) >= 5
            )
    ```

   - 方法2
  
    ```sql
        -- 第一步的结果作为临时表，然后join
        SELECT
            e1. NAME AS NAME
        FROM
            Employee AS e1
        JOIN (
            SELECT
                ManagerId
            FROM
                Employee e
            GROUP BY
                ManagerId
            HAVING
                ManagerId != 'null'
            AND count(ManagerId) >= 5
        ) AS e2 ON e1.Id = e2.ManagerId
    ```

3. 还可以根据id = managerid，来对Employee表进行自连接，这样可以自然过滤掉managerid为null的数据，然后我们只需根据Id对产生的笛卡尔积进行分组，然后having出现5次及以上的Name，打印即可

   - 方法3
  
    ```sql
        -- 自连接过滤
        SELECT
            e1. NAME
        FROM
            Employee AS e1
        JOIN Employee AS e2 ON (e1.id = e2.managerid)
        GROUP BY
            e1.id
        HAVING
            count(e1.id) >= 5
    ```