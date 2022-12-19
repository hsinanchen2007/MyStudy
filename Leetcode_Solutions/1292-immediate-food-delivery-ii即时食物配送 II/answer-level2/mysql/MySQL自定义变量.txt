之前使用@pre=0，时一直会有一定的差错。
```
  select  round(sum(num)/(select count(distinct customer_id)from Delivery) *100 ,2) as immediate_percentage from (
        select 
if(
case when @customer = customer_id then  @num:= @num +(@pre<>@pre:=order_date)
     when @customer := customer_id then @num:=1
     else @num :=1
     end  
     = 1 and datediff(customer_pref_delivery_date,order_date)=0 ,1,0
) 
as num 
 from Delivery d ,(select @num:=0,@pre:=null,@customer:=0) b  
  order by customer_id,order_date asc 
  )t ;
```
