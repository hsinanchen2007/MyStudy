题目本身很简单，只要调用系统自带的排序函数，然后自己改写一下排序规则即可，所以这里主要讲讲如何计算数字二进制下 $1$ 的个数。

#### 方法一：暴力

对每个十进制的数转二进制的时候统计一下 1 的个数即可。

```C++ []
class Solution {
    #define N 10010
    int bit[N];
public:
    int get(int x){
        int res=0;
        while (x) res+=x&1,x>>=1;
        return res;
    }
    vector<int> sortByBits(vector<int>& arr) {
        for (auto x:arr) bit[x]=get(x);
        sort(arr.begin(),arr.end(),[&](int x,int y){
            return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        });
        return arr;
    }
};
```

#### 方法二：递推预处理

我们定义 $bit[i]$ 为数字 $i$ 二进制表示下数字 1 的个数，则可以列出递推式：

$$bit[i]=bit[i>>1]+(i\&1)$$

所以我们线性预处理 $bit$ 数组然后去排序即可。

```C++ []
class Solution {
    #define N 10010
    int bit[N];
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (int i=1;i<=10000;++i) bit[i]=bit[i>>1]+(i&1);
        sort(arr.begin(),arr.end(),[&](int x,int y){
            return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        });
        return arr;
    }
};
```
**复杂度分析**

- 时间复杂度：$O(nlogn)$ 。
- 空间复杂度：$O(n)$ 。

#### 方法三： 系统库函数

C++ 自带库函数 $\_\_builtin\_popcount(x)$ ：统计 $x$ 在二进制下的数字 $1$ 的个数，内部实现是用查表实现的。

```C++ []
class Solution {
    #define N 10010
    int bit[N];
public:
    vector<int> sortByBits(vector<int>& arr) {
        for (auto x:arr) bit[x]=__builtin_popcount(x);
        sort(arr.begin(),arr.end(),[&](int x,int y){
            return bit[x]==bit[y]?x<y:bit[x]<bit[y];
        });
        return arr;
    }
};
```

**复杂度分析**

- 时间复杂度：$O(nlogn)$ 。
- 空间复杂度：$O(n)$ 。