```
SELECT FirstName, LastName, City, State
FROM Person p
LEFT JOIN Address USING(PersonId)
```
