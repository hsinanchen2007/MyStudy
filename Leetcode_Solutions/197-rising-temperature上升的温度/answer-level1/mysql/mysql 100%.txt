select w2.id from 
weather w1
left join weather w2
on date_add(w1.recordDate, interval 1 day) = w2.recordDate
where w2.Temperature > w1.Temperature