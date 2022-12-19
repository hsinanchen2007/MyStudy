select P1.FirstName,P1.LastName,A1.City,A1.State from Person P1 ,Address A1 where 1=1
AND P1.PersonId = A1.PersonId

耗时也要少一些，不知道错在哪里。