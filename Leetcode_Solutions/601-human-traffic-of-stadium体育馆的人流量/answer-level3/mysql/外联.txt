```
select s3.* from stadium s3
left join stadium s1 on s1.id = s3.id - 2
left join stadium s2 on s2.id = s3.id - 1
left join stadium s4 on s4.id = s3.id + 1
left join stadium s5 on s5.id = s3.id + 2
where 
(s1.people >= 100 and s2.people >= 100 and s3.people >= 100) 
or (s2.people >= 100 and s3.people >= 100 and s4.people >= 100)
or (s3.people >= 100 and s4.people >= 100 and s5.people >= 100)
```
这是我想到的方法，供大家参考一下吧