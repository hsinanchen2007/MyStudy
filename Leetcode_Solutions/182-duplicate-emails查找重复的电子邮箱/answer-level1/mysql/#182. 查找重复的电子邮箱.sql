### i
```mysql
SELECT 
    Email
FROM
    Person
GROUP BY Email
HAVING COUNT(Email) > 1;
```

### ii
```mysql
SELECT 
    Email
FROM
    (SELECT 
        Email, COUNT(Email) AS num
    FROM
        Person
    GROUP BY Email) AS tmp
WHERE
    tmp.num > 1;
```