### 解题思路
此处撰写解题思路
偷懒了，用SQL SERVER里的窗口函数。
有点像做辅助线一样的制造2个辅助列
    第一个辅助列，以username为分割点，给这个username参与的活动按时间倒序排列编号，比如alice干了3件事情，那么alice所在行会被一次标记上3,2,1。第2个就是倒数第2件事情，英文里面 second most recent activity了，注意此处中文翻译是错误的！！！
    考虑到如果只有1个活动要返回这个活动，于是再做1个辅助列，count所有username的活动数量。如果你干了3件事情，那么这个username全部行都会显示3，如果你干了1件事情，这个username行会显示1.
    最后就是按题目要求select了
        然后筛选条件用上辅助列，干了2件事以上的，就会被 rank1 =2 选中，只干了1件事情的，就会被count1 =1 选中。



### 代码

```mssql
/* Write your T-SQL query statement below */

SELECT u1.username,u1.activity,u1.startDate,u1.endDate
from(
SELECT *,
    rank() over(partition by username order by startDate desc ) as 'rank1',
    COUNT(*)over(partition by username  ) as 'count1'
FROM UserActivity) as u1
WHERE rank1 = 2 
or count1 =1
 
```