select a.Name as Employee from Employee a left join Employee as b on a.ManagerId  = b.Id where a.Salary > b.Salary and a.ManagerId is not NUll; 
执行用时 :519 ms, 在所有MySQL提交中击败了82.17%的用户