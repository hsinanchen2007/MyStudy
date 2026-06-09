#  丑数 II
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

```
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```
说明:  

1 是丑数。
n 不超过1690。

<hr>

##  解：
我们可以发现后面的丑数都是可以通过前面的丑数乘以2，3，5得来，但是如果我们直接用前面的数直接乘以2，3，5得到后面的丑数的话会发现出现重复的丑数而且没有进行排序。

## 思路：
用三个指针分别指向2，3，5要乘的位置

##  实现代码：

```
class Solution {
public:
    int nthUglyNumber(int n) {
        int *res=new int[n];
        res[0]=1;
        int *ugly2=res;
        int *ugly3=res;
        int *ugly5=res;
        int next=1;
        while(next<n)
        {
            int min1=min(min(*ugly2 *2,*ugly3 *3),* ugly5 *5);
            res[next]=min1;

			//排除重复项以及找到对应位置
            while(*ugly2 *2<=res[next])
            {
                ++ugly2;
            }
            while(*ugly3 *3<=res[next])
            {
                ++ugly3;
            }
            while(*ugly5 *5<=res[next])
            {
                ++ugly5;
            }
            next++;
        }
        return res[n-1];
    }
};
```

