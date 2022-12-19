select t.id id from(
select id,temperature,RecordDate,lag(temperature,1) over(order by RecordDate) as pretemp,lag(RecordDate,1) over(order by RecordDate) as pretime from weather)t
where ROUND(TO_NUMBER(t.RecordDate - t.pretime))=1
and t.temperature>t.pretemp;