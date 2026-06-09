### 解题思路
[Catalan数](https://baike.baidu.com/item/catalan/7605685?fr=aladdin) 递推公式.
我们知道 $G(n)= \sum_{i=1}^n G(i-1) \cdot G(n-i)$，其中`G(0)=G(1)=1`。要求得`G(n)`，只需知道
$G(0),G(1),\cdots,G(n-1)$.

这里，需要注意的是，递归的过程应该按照`0,1,...,n-1`的顺序计算亚特兰数，并且保存计算结果，最终返回`G(n)`

如果直接递归，即套用$G(n)= \sum_{i=1}^n G(i-1) \cdot G(n-i)$，会重复计算$G(0),G(1),\cdots,G(n-1)$的值，`n`比较大的时候耗时会很长。

结果以及代码如下:
![lc96递归.PNG](https://pic.leetcode-cn.com/05256a663223ab9dad6dae5eb74f2ab3e561100100f0b1288a22653df33f64dc-lc96%E9%80%92%E5%BD%92.PNG)

### 代码

```cpp
/*
** 递归
** Cantlan 数递推公式
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> Cantlan(n+1,0);
        Cantlan[0]=1;
        Cantlan[1]=1;
        for(int i=2;i<n+1;i++)
        for(int j=1;j<=i;j++)
        Cantlan[i]+=Cantlan[j-1]*Cantlan[i-j];
        return Cantlan[n];
    }
};
```