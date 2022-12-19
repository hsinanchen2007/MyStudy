### 思路1
1. 排名第N的薪水意味着该表中存在N-1个比其更高的薪水
2. 注意这里的N-1个更高的薪水是指去重后的N-1个，实际对应人数可能不止N-1个
3. 最后返回的薪水也应该去重，因为可能不止一个薪水排名第N

### 代码1
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT e.salary
      FROM employee e
      WHERE (SELECT count(DISTINCT salary) FROM employee WHERE salary>e.salary) = N-1
  );
END
```

### 思路2
一般来说，能用子查询解决的问题也能用连接解决。具体到本题：
1. 两表自连接，连接条件设定为表1的salary小于表2的salary
2. 以表1的salary分组，统计表1中每个salary分组后对应表2中salary唯一值个数，即去重
3. 限定步骤2中having 计数个数为N-1，即实现了该分组中表1salary排名为第N个
4. 考虑N=1的特殊情形(特殊是因为N-1=0，计数要求为0)，此时不存在满足条件的记录数，但仍需返回结果，所以连接用left join

注：个人认为无需考虑N=0的情形，没有第0高这一说，无实际意义。

### 代码2
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT e1.salary
      FROM employee e1 LEFT JOIN employee e2 ON e1.salary < e2.salary
      GROUP BY e1.salary
      HAVING count(DISTINCT e2.salary) = N-1
  );
END
```

### 思路3
以上两种方法都存在两表关联的问题，表中记录数少时还好，当表中比较大且无法建立合适索引时，实测速度会比较慢，用算法复杂度来形容就是O(n^2)量级。那么，用下面的自定义变量的方法可实现O(2*n)量级，速度会快得多，且与索引无关。
1. 自定义变量，对按薪水降序后的数据排名，其中同薪同名且不跳级，即3000、2000、2000、1000排名后为1、2、2、3；
2. 对带有排名信息的临时表二次筛选，得到排名为N的薪水；
3. 因为薪水排名为N的记录可能不止1个，用distinct去重

### 代码3
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary 
      FROM (SELECT salary, @r:=IF(@p=salary, @r, @r+1) AS 'rank',  @p:= salary 
            FROM  employee, (SELECT @r:=0, @p:=NULL)init 
            ORDER BY salary DESC) tmp
      WHERE rank = N
  );
END
```

### 思路4（当前OJ不支持，仅限8.0以上版本）
实际上，思路3中的方案在mysql8.0中有相关的内置函数，而且考虑了各种排名问题：
- row_number(): 同薪不同名，相当于行号，例如3000、2000、2000、1000排名后为1、2、3、4
- rank(): 同薪同名，有跳级，例如3000、2000、2000、1000排名后为1、2、2、4
- dense_rank(): 同薪同名，无跳级，例如3000、2000、2000、1000排名后为1、2、2、3

显然，本题是要用第三个函数。
另外这三个函数必须要要与其搭档over()配套使用，over()中的参数常见的有两个，分别是
- partition by，按某字段分组
- order by，与常规order by用法一致，也区分ASC(默认)或者DESC，因为排名总得有个依据啊

注：下面代码仅在mysql8.0以上版本可用，当前OJ不支持。

### 代码4
```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT salary
        FROM (SELECT salary, dense_rank() over(ORDER BY salary DESC) AS 'rank' FROM employee) tmp
        WHERE rank = N
  );
END
```
看到这里了，如果你觉得有收获还不关注一下个人公众号吗：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
