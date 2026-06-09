> 最简单的方法当然是dense_rank()函数，直接搞定，这里就顺便复习一下自己之前也遇到过的类似的排名解法
>就不使用dense_rank了，以下建立在没有dense_rank函数的情况下

从零开始的思路讲不出来，因为我第一次做这个题(如果不能用dense_rank)我也是毫无头绪。
所以作为一只猪可能做不出这个题，哎

##那么正式开始：
从查询应该返回的结果进行思考，这个思路很实用的
那么查询结果需要的是一栏 score 一栏 rank

score 的顺序可以用order by score desc 来实现
那么rank这一栏，肯定是自己生成的数字，且具有计数功能的函数 比如 count(), sum()之类的
sum()不太可行, 无论是id的累加还是score的累加都没办法给出序数
选用count()貌似可行，直接操作：
变出两张score表，s1, s2, 就将两张表以逗号罗列，形成笛卡尔乘积 s1 x s2
以group by s1.id 分组
则 每一组s1.id 内都包含着s2的所有id
那么接下来
s1作为主要score表，s2作为一张参照表，进行比较：
当 s1.id < s2.id 时，这个时候，比s1.id对应score大的分数的个数就应该是s1.id的rank了
如下图所示，蓝色是被group起来的状态，用土黄色画出了每一组中比s1.id大的个数
![image.png](https://pic.leetcode-cn.com/6eec8e326bdb8f31c70a12436544bbaff4f7f1f3744a1457a7f228441af9a50b-image.png)

此时每一个对应的s1.id 都会拥有一个对应的count数，而这个count就是该id对应score的名次
仅剩的问题就是：如果表中有重复出现的score怎么办？同score要求同排名

用distinct去重即可

**SQL：**
```
select s1.score as score, count(distinct s2.score) as rank
from scores as s1, scores as s2 
where s1.score <= s2.score
group by s1.id
order by s1.score desc
```

小注意：
group by 和 order by的顺序
先group by 后 order by