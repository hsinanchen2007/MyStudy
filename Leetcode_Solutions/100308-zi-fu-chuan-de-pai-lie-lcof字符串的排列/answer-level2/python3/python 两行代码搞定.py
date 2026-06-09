![Xnip2020-03-25_15-26-52.jpeg](https://pic.leetcode-cn.com/10775362df4f9a2c0908e29ebd62082e7b8fd7e0b98255bfab9e4b98cbd51013-Xnip2020-03-25_15-26-52.jpeg)

`list(set())`：是为了去重，如果输入为“aab”，则输出结果只有3个，不去重的话则有6个
**这只是内置函数的一个使用，要想练习思维还是多看看算法层面的实现吧～**

```
import itertools
return list(set([''.join(i) for i in itertools.permutations(s,len(s))]))
```
