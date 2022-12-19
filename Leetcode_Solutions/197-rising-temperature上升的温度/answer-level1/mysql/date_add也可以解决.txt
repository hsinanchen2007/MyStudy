
select w.Id from Weather as w, Weather as e where date_add(e.RecordDate, interval 1 day) = w.RecordDate and w.Temperature > e.Temperature;