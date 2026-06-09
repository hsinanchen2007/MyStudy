由函数的单调性可以得到以下表格
![图片2.png](https://pic.leetcode-cn.com/c64e995dbdb83aad9ca47e612b8a76f7d04baae20feb464d682126b7eca892f3-%E5%9B%BE%E7%89%872.png)
有以上表格分析得到:
1. 每行严格递增
2. 每列严格递增

那么问题就变成了[搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)
从左下角与右上角开始搜索都可以得到答案。
以下是c++实现：
```cpp
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        int x = 1;
        int y = 1000;
        vector<vector<int>> re;
        while(x<1001 && y>0){
            int fz = cf.f(x,y);
            if(fz>z) --y;
            else if(fz <z) ++x;
            else{
                re.push_back({x,y});
                --y;
            }
        }
        return re;
    }
};
```

另外，由于每行每列都是有序的，因此在每行或者每列上二分也是可行的。
以每行中搜索为例：
```cpp
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& cf, int z) {
        vector<vector<int>> re;
        for(int x=1;x<1001;x++){    // 遍历每一行
            int l = 1;
            int r = 1000;
            while(l<r){     // 二分
                int m = (r+l)/2;
                if(cf.f(x,m)>=z) r=m;
                else l=m+1;
            }
            if(cf.f(x,l)==z) re.push_back({x,l});
        }
        return re;
    }
};
```

上面的解法都可以在[搜索二维矩阵II题解](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/)中找到对应的方法求解，这里就不再列举了。

#### 补充:
对于解法1中为什么只能从左下角与右上角搜索，上述[题解](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/)中的评论区可以找到答案。
对于解法2二分的写法可以参考[二分查找框架](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/)(个人觉得是总结地比较好)。
