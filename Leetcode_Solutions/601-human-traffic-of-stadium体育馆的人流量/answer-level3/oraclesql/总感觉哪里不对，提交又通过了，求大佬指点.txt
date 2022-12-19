 select a.id, to_char(a.visit_date,'yyyy-mm-dd') visit_date, a.people
![体育馆的人流量.png](https://pic.leetcode-cn.com/8bf983962ba743cf977e934105656119273d96ba650d2100243c088c8dab12ad-%E4%BD%93%E8%82%B2%E9%A6%86%E7%9A%84%E4%BA%BA%E6%B5%81%E9%87%8F.png)
   from (select id, visit_date, people, (id - rownum) rn
           from stadium
          where people >= 100) a,
        (select rn, count(rn) countrn
           from (select id, visit_date, people, (id - rownum) rn
                   from stadium
                  where people >= 100)
          group by rn) b
  where a.rn = b.rn
    and b.countrn >= 3
    order by id;

求大佬有空帮我看一下


--------------------------------------------------------------------------
![体育馆人流量.png](https://pic.leetcode-cn.com/6559d3fb666165023fd47fabab6ef302fd38ada9a7826c39adeafa2903d71ff2-%E4%BD%93%E8%82%B2%E9%A6%86%E4%BA%BA%E6%B5%81%E9%87%8F.png)

第二种方法

