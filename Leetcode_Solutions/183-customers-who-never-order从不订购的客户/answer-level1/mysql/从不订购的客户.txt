这道题的陷阱就在于不能通过名字进行筛选，因为不同的人消费记录不一样，但名字却可能一样，如果通过名字筛选的话，会把未消费的人当作消费过的人，所以我最后选择的是通过Id进行筛选，每一个人只能有一个Id。

我的解题答案👇

select Name as Customers from Customers 
where Id not in (
    select c.Id 
    from Customers c join Orders o
    on c.Id = o.CustomerId )