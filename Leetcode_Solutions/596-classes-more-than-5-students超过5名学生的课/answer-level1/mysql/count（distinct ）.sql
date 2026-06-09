select class
from courses
group by class
having count(distinct student) >= 5;

重点：因为无法保证是否有重复数据，需要用到distinct