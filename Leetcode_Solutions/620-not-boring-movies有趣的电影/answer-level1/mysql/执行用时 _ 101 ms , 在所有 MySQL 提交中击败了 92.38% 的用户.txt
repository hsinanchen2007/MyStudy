### 解题思路
此处撰写解题思路
![QQ图片20200326203047.png](https://pic.leetcode-cn.com/624155432026deb707d48f18336709df95c142804f838c16ff3a42121d86fde5-QQ%E5%9B%BE%E7%89%8720200326203047.png)

### 代码

```mysql
# Write your MySQL query statement below
SELECT * FROM cinema WHERE description <> 'boring' AND MOD(id, 2) = 1 ORDER BY rating DESC;
```