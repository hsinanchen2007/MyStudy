![image.png](https://pic.leetcode-cn.com/877a2987b6cff43e10637ebfa1cd575976cb48c13defec2e4d23e867c0ac25ec-image.png)

也不知道我怎么想的···  先构造了一个长度为15的有环的链表,然后在3、6、9、12上val赋值为'Fizz',5和10上赋值'Buzz',15上赋值'FizzBuzz'.
然后不断的循环这个链表打印就行,val为null的时候就打印数字.
内存使用轻喷···