### 解题思路
本题的难点在于如何实现分类排序。
简单起见，我们首不考虑department表信息，仅利用employee表中给出的部门id实现分类。
分类排序中，需执行如下逻辑：
- 将当前表按部门和salary从高到低进行排序，则同一部门的所有薪资集中，并且是按从高到低排序
- 自定义三个变量：@pD，表示上一个部门id，初始化为null；@pS，表示上一个薪资，初始化为null，当然这里的上一个薪资可能是同部门也可能是不同部门；@r，表示当前排名，初始化为0（虽然MySQL不区分大小写，但我们在书写中仍然加以区分方便识读。另外，这里选择用一个虚拟表的方式进行变量初始化）
- 执行以下逻辑：
-    A. 如果当前部门id与前一部门id相同（@pD=DepartmentId），则排名信息是在当前部门的基础上进行更新，又区分两种情况：
   - - 与前一薪资相同（@pS=salary），则排名不变（@r:=@r）
   - - 否则排名+1（@r:=@r+1）
-    B. 如果当前部门id与前一部门id不同，则说明排名需重新开始，所以排名赋值为1（@r:=1）

在得到排名信息表的基础上，仅需简单的与部门表join关联提取部门名字信息，并对相应字段按要求重新改名即可。

另外，因为力扣执行环境为5.7版本，不支持内置窗口函数。若是在8.0以上版本，可直接调用内置函数实现排名，且效率要更高一些：
- row_number()，连续排名，同分不同名，例如90、80、80、70，排名后是1、2、3、4
- rank()，同分同名，但是跳级，例如90、80、80、70，排名后是1、2、2、4
- dense_rank()，致密排名，同分同名，不跳级，例如90、80、80、70，排名后是1、2、2、3
本题即为dense_rank()的情况。

### 结果
![image.png](https://pic.leetcode-cn.com/2bee99bca6e76fa30d9507cdfd6a29d2ad6ca8dcc34e42001903d7773d1d9578-image.png)


### 代码

```mysql
# Write your MySQL query statement below
SELECT 	
   d.NAME department, t.NAME employee, salary 
FROM
   ( SELECT 
      *, @r := IF(@pD = departmentid, IF(@pS = salary, @r, @r + 1 ), 1 ) AS 'rank',
      @pD := departmentid,
      @pS := salary 
     FROM 
      employee, ( SELECT @pS := NULL, @pD := NULL, @r := 0 ) init 
     ORDER BY
      departmentid, salary DESC ) t
   JOIN department d ON t.departmentid = d.id 
WHERE
   t.rank <=3
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)