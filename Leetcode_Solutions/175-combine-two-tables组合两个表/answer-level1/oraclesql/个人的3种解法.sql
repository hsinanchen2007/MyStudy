**【方法一】：最简单直接，通俗易懂的左外连接**
```
select p.firstname
       ,p.lastname
       ,a.city
       ,a.state 
 from Person p 
 left join Address a on(p.personId = a.personid)
```
此方法提交后用时为：2137ms

**【方法二】：对地址表字段进行2次关联查询（SQL长，但是效率高一点）**
```
select p.firstname
       ,p.lastname
       ,(select a.city from address a where p.personid = a.personid) city
       ,(select a.state from address a where p.personid = a.personid) state
 from Person p
```
此方法提交后用时为：931ms
**【方法三】：仍然为左外连接，但是用（+）语法代替left on用法**
```
select p.firstname
       ,p.lastname
       ,a.city
       ,a.state
 from Person p
      ,Address a 
 where p.personid = a.personid(+)
```
此方法提交后用时为：487ms

提交记录如下图：
![image.png](https://pic.leetcode-cn.com/0f28112b810065664dea77da5b55d4252671da4f574cc9578c751efe352a75a9-image.png)

对于具体的原因本人目前还是一知半解，还在学习中，也希望对sql底层逻辑熟悉的朋友如果愿意，可以帮我分析一哈子，感谢喽


