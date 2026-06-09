```
select * from cinema
where description<>'boring' and id%2=1
order by rating desc;
```
一道基本题目，事实证明sql也支持%运算