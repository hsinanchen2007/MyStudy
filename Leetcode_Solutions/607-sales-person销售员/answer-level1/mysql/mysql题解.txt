/*
这么求解是错误的，一是像Pam既卖个RED也卖过非RED，还有的员工没有开张，比如Amy
select S.name
from salesperson S,company C,orders O
where O.com_id=C.com_id and O.sales_id=S.sales_id and C.name!="RED"
*/

select name
from salesperson
where sales_id not in
(select O.sales_id
from company C,orders O
where C.com_id=O.com_id and C.name="RED")