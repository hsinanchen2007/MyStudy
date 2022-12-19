先筛选出人流量大于100的记录，若id连续则归为一组。
```
SELECT r1.*,@zu :=IF(r1.id>@zid+1,@zu+1,@zu) AS `p`,@zid :=id AS `q` FROM 
(SELECT * FROM stadium WHERE people>=100) r1,(SELECT @zu :=1,@zid :=0) t1
```
![1.JPG](https://pic.leetcode-cn.com/e7b237ebc2b2fb0c39dbbb93dcef6fe36d03af47a2be461c925e6183121ff533-1.JPG)
字段p为组别，然后分组统计成员数量。
```
SELECT te.p AS pl,COUNT(*) AS k FROM
(SELECT r2.*,@zu_c :=IF(r2.id>@zid_c+1,@zu_c+1,@zu_c) AS `p`,@zid_c :=id AS `q` FROM 
(SELECT * FROM staduim WHERE people>=100) r2,(SELECT @zu_c :=1,@zid_c :=0) t2) te
GROUP BY te.p
```
![2.JPG](https://pic.leetcode-cn.com/689ecd6d39e714fa8ec10abe6101acf25a9733c079c16f7874017ca3085bdaf3-2.JPG)

pl为组别，k为组员数量。

最后将两个表左连接，在筛选出组员数量大于等于3的记录即可。
```
SELECT gh.id AS id,gh.visit_date AS visit_date,gh.people AS people FROM
(SELECT r1.*,@zu :=IF(r1.id>@zid+1,@zu+1,@zu) AS `p`,@zid :=id AS `q` FROM 
(SELECT * FROM stadium WHERE people>=100) r1,(SELECT @zu :=1,@zid :=0) t1) gh 
LEFT JOIN
(SELECT te.p AS pl,COUNT(*) AS k FROM
(SELECT r2.*,@zu_c :=IF(r2.id>@zid_c+1,@zu_c+1,@zu_c) AS `p`,@zid_c :=id AS `q` FROM 
(SELECT * FROM stadium WHERE people>=100) r2,(SELECT @zu_c :=1,@zid_c :=0) t2) te
GROUP BY te.p) gn
ON gh.p=gn.pl
WHERE gn.k>=3
ORDER BY gh.id;
```
![3.JPG](https://pic.leetcode-cn.com/50935eacceccb53c2586d0c80f9eb7d56cb3a23ac49bea1b97a1cb09ada02a22-3.JPG)

