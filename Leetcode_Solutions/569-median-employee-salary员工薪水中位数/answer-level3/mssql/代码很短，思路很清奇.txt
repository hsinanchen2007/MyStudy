### 解题思路
最难点是怎么找出来中位数，灵机一动，想到：
先给数字编号 a) 当数字是奇数位数的时候，编号1 2 3，倒过来是3 2 1， 两者相减， 则差值是0的就是中位数了。
            b) 当数字是偶数的时候，编号1 2 3 4，倒过来是4 3 2 1 ，两者相减，差值是-1,1的就是中位数了。
以此类推，都是成立的。
大喜，开始写代码，结果发现了一个bug... 就是当组的位数是奇数的时候，如果有相同的金额，而恰巧这个金额就是中位数的时候，正着编号跟反着编号，同金额的数可能不一样，导致正逆编号相减，中间的数不为0，多出了-1，和1了。
wtf！！！ 为了避免这种问题，只好加了group by ，把那个相同的金额，但是编号大的数剔除掉。。。
代码应该属于比较短的，但耗资源较多。


### 代码

```mssql
/* Write your T-SQL query statement below */

select min(id) as id,company,salary 
from 
        (
        select id,company,salary,
            case when (num2-num1) in (-1,0,1) then 1 else 0 end as win
        from (
                select id,company,salary,
                row_number() over(partition by Company order by salary) as num1,
                row_number() over(partition by Company order by salary desc) as num2
                from Employee ) a )b
where win = 1
group by company,salary
order by company,salary  
 

```