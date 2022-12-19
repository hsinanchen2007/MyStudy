第一步、一个id关联 自身及附近的id (如T1.id=2  则T2.id = 1、2、3  共三条记录 均满足关联条件）
第二步、过滤掉100以下的id，然后统计该id关联出来的数据条数，如果数量等于三，则代表 1、2、3一定均大于100。
第三步、利用查询出的ID   回关联原表 并去重（第三步需要注意 如果id=2符合条件，则代表id=1、id=3也符合条件）



SELECT DISTINCT TT.* FROM stadium TT
INNER JOIN (
SELECT T1.id,COUNT(*) FROM stadium T1
INNER JOIN stadium T2
ON( T1.id=T2.id
OR T1.id=T2.id+1
OR T1.id=t2.id-1
)
WHERE T2.people>100
GROUP BY T1.id
HAVING COUNT(*)>=3
) TID
ON TT.id=TID.id
OR TT.id+1=TID.id
OR TT.id-1=TID.id


![image.png](https://pic.leetcode-cn.com/01afa5adb15c65e74324549e50bee1f762af8d107a0b657b4ce900160e281557-image.png)
