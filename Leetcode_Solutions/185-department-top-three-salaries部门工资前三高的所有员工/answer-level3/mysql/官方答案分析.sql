对于官方答案的分析如下：
    				FROM
					Employee e1
					JOIN Department d ON e1.DepartmentId = d.Id 
				执行完这句后会生成以下这个表：
![image.png](https://pic.leetcode-cn.com/4292c811d52ae9affe290bdba9b8652572b3ac1d3f0749fd277ec8be10f56054-image.png)
				接着执行where条件，执行where条件的时候其实是一行一行的做条件筛选的，就是先拿第一行出来，然后根据where条件判断返回true或者false，再确定是否需要保留这行，以此类推；
				先理解where条件内容的意思：
					3 > (
						SELECT
							COUNT( DISTINCT e2.Salary ) 
						FROM
							Employee e2 
						WHERE
						e2.Salary > e1.Salary 
						AND e1.DepartmentId = e2.DepartmentId 
					)
				从执行上看，其实就相当于一个双层for循环：
					从e1拿出一行记录比如说是A，然后再取出一张全表e2，对e2进行一行一行的读取判断，这里有两个条件，简单点说就是从全表找和A同个部门而且薪水比A高的人数共有几个（比较薪水的时候需要去重，所以使用distinct），如果说这个人数小于3的话，就说明A本身就是薪水排名前3的，同时，A的这行记录也会被保存下来。
				以此类推，再继续读下一行；