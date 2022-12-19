### 解题思路
此处撰写解题思路
写的第一次，提交结果执行时间只打败6%，那就是效率很低了，然后看见可以join，试了下，这种稍微高些，不懂为什么where比join效率低，需要了解它的工作机制。
并且看了下部分其他人的题解，遇见两个效率更高的，一个是在join里不是把整个表join而是先筛出id和工资，然后join,还有一个是去空外连接（她比较了内外连接效率不同，发现外连接效率更高）。
所以是不是把数据筛得越多（操作相应多了，但可能比较少了）y效率越高。
### 代码

```mysql
# Write your MySQL query statement below
select a.Name as Employee
from Employee a
join Employee b
on a.ManagerId=b.Id and a.Salary>b.Salary;
```