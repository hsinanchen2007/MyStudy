select S.buyer_id
from Sales S left join Product P
on P.product_id=S.product_id
group by S.buyer_id
having sum(if(P.product_name="S8",1,0))>0 and sum(if(P.product_name="iPhone",1,0))=0