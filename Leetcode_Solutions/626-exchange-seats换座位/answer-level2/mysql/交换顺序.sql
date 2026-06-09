### 解题思路
本题是我第一次做中等难度的题，此题逻辑上难度并不大，对于我而言主要在于对于SQL语言的理解还不够到位，对语法不够熟练。
对于此题我的收获是：
select语句可以用作查询并比大小，只要保证得到的结果是标量即可；
select中加入判断语句就是对这一投影列的所有元素进行一一的判断然后操作，可以在此过程中进行赋值

### 代码

```mysql
select if(id%2=0, id-1, if(id=(select count(id) from seat), id, id+1)) as id, student
from seat
order by id;


```