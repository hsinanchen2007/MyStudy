提供了三种方法,第一种自己想的，其他两个参考别的大佬的

# 方法一 : 异或
我在学习网络流的时候学到了 0^1=1 , 1^1=0 ,2^1=3 ,3^1=2 ，以此类推，于是这题就用到了
代码如下
```
select b.id,a.student from seat as a,seat as b,(select count(*) as cnt from seat) as c where b.id=1^(a.id-1)+1 || (c.cnt%2 && b.id=c.cnt && a.id=c.cnt);
```

# 方法二 ：对Id排序
因为 from 后面两个数据表没有重复的列名，所以不用重命名。
```
select if(id%2=0,id-1,if(id=cnt,id,id+1)) as id,student from (select count(*) as cnt from seat)as a,seat order by id;
```

# 方法三 ： 左连接
```
select a.id,ifnull(b.student,a.student) as student from seat as a left join seat as b on (a.id%2=1 && a.id=b.id-1) || (a.id%2=0 && a.id=b.id+1) order by a.id;
```


**三种方法的时间基本都是127ms，都差不多**