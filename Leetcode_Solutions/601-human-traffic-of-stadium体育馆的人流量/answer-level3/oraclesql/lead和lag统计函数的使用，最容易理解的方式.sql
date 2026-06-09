--先按照date进行排序，生成rownum的伪列rn，这个rn我们要用来取rn-1,rn+1的数据
with a as (select id,rownum as rn, visit_date ,people from stadium order by visit_date asc)

--首先，题目要求至少连续三天，那么就是这三天中的中间一行，它的前一天，后一天以及它本身的人员数量一定是大于等于100的。我们可以从这里入手
![image.png](https://pic.leetcode-cn.com/3d33e02cec9ea74cd1cb3135b1ad3150bc7108a8719ec4e0e5249eb25ec2e0ce-image.png)

--一行一行遍历，当便利到第四行的时候，people为99，它的前一行和后一行peolple分别是150和145，但是他自己不满足条件所以略过，
--再遍历到第五行，它的上一行是99，不满足条件，略掉。再遍历第六行，此时145，1455，199，满足连续三行条件。再遍历第七行，此时1455，199，188，仍然满足条件。但是id6，id7的我们已经得到过了。所以结果集一定存在一个distinct。

,b as (
select id from (
select id,people
                    ,lag(people,1,0)over(order by visit_date) as people1
                    ,lead(people,1,0)over(order by visit_date) as people2
from a
    ) s where people>=100 and people1>=100 and  people2>=100
    )

--例如b.id是6，那么它的前一行的rn和后一行的rn对应的id我们可以再一开始的字表a中找到对应关系。,b.id=5是不存在的，因为id=5
的前一行数据是99，不满足条件所以id=5被过滤掉了。
,c as (select rn,rn-1 as rn1,rn+1 as rn2 from a,b where a.id = b.id)

--上一步C表我们找到了所有需要被查出来的行的rn序号，所以我们直接查子表a就可以了。
select distinct a.id,to_char(visit_date,'yyyy-MM-dd') as visit_date,people from a,c where a.rn = c.rn or a.rn = c.rn1 or a.rn = c.rn2  order by visit_date asc