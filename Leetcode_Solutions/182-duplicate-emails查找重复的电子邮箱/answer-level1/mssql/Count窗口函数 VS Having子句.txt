* 窗口函数  
四轮测试，最高93%
```
with New as 
(
    SELECT distinct Email,Count(Email) over(partition by Email) as Num from [Person]
)
select Email from New where Num>1;
```
* Having子句  
四轮测试，最高95%
```
select Email from [Person] group by Email having Count(Email)>1;
```