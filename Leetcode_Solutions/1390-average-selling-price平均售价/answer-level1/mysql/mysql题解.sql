select U.product_id,Round(
    Sum(U.units*P.price)/sum(U.units),2
)average_price
from UnitsSold U,Prices P
where U.product_id=P.product_id and U.purchase_date between P.start_date and P.end_date
group by U.product_id