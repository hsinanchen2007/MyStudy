```
with New as
(
    Select Id,Num,lead(Num,1) over(order by Id) Next, lead(Num,2) over(order by Id) NNext from Logs
)
select distinct Num as ConsecutiveNums from New where Num=Next and Num=NNext;
```
