

做一个虚拟表 当people 大于等于 100 tag 标记为1  @a+1 以此下个大于等于100 继续加1  小于100 @a归0 
SELECT id,people, IF (people >= 100 ,@a :=@a + 1 ,@a := 0) AS tag FROM `stadium`, (SELECT @a := 0) t 

![1570630389(1).jpg](https://pic.leetcode-cn.com/315766c7fc662476b02d3af72e2b9299153b8aef772709f86618f7eea0777391-1570630389\(1\).jpg)


符合条件的 id 就是 >=3  以及 等于3所对应 id-1 id-2的

SELECT * FROM stadium where id in
(SELECT id  FROM(SELECT id, IF (people >= 100 ,@a :=@a + 1 ,@a := 0) AS tag FROM `stadium`, (SELECT @a := 0) t )t3 WHERE tag >= 3 ) or 
 id in
 (SELECT id-1  FROM(SELECT id, IF (people >= 100 ,@b :=@b + 1 ,@b := 0) AS tag FROM `stadium`, (SELECT @b := 0) t )t3 WHERE tag =3 ) or 
 id in 
 (SELECT id-2  FROM(SELECT id, IF (people >= 100 ,@c :=@c + 1 ,@c := 0) AS tag FROM `stadium`, (SELECT @c := 0) t )t3 WHERE tag = 3 )