#### 方法：使用 "session 变量" 和 `join`【通过】

**思路**

为每个大洲分配一个单独的行自增 id，然后将它们连接。

**算法**

使用 session 变量为每个大洲分配单独的行自增 id。例如下面语句为美洲的学生分配行自增 id。

```mysql [snippet1-MySQL]
SELECT 
    row_id, America
FROM
    (SELECT @am:=0) t,
    (SELECT 
        @am:=@am + 1 AS row_id, name AS America
    FROM
        student
    WHERE
        continent = 'America'
    ORDER BY America) AS t2
;
```

```
| row_id | America |
|--------|---------|
| 1      | Jack    |
| 2      | Jane    |
```

同理，为其他大洲分配单独的行自增 id。

```
| row_id | Asia |
|--------|------|
| 1      | Xi   |
```

```
| row_id | Europe |
|--------|--------|
| 1      | Jesper |
```

然后使用相同的 `row_id` 将这 3 个临时表连接，得到下表。

```
| row_id | America | Asia | Europe |
|--------|---------|------|--------|
| 1      | Jack    | Xi   | Pascal |
| 2      | Jane    |      |        |
```

这里有一个问题，如果使用内连接，那么美洲的学生记录会显示不完整，所以应该使用外连接。另外也应该将美洲的学生表放在中间，然后使用 `right (outer) join` 和 `left (outer) join` 连接另外两张表。

**MySQL**

```mysql [solution1-MySQL]
SELECT 
    America, Asia, Europe
FROM
    (SELECT @as:=0, @am:=0, @eu:=0) t,
    (SELECT 
        @as:=@as + 1 AS asid, name AS Asia
    FROM
        student
    WHERE
        continent = 'Asia'
    ORDER BY Asia) AS t1
        RIGHT JOIN
    (SELECT 
        @am:=@am + 1 AS amid, name AS America
    FROM
        student
    WHERE
        continent = 'America'
    ORDER BY America) AS t2 ON asid = amid
        LEFT JOIN
    (SELECT 
        @eu:=@eu + 1 AS euid, name AS Europe
    FROM
        student
    WHERE
        continent = 'Europe'
    ORDER BY Europe) AS t3 ON amid = euid
;
```