delete from Person where Id not in(select Id from (SELECT
  Email,
  SUBSTRING_INDEX(GROUP_CONCAT(Id ORDER BY Id asc ),',',1) Id
FROM (SELECT *
      FROM Person) t
GROUP BY Email) r)