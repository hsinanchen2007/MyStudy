### 解题思路
#### 参考这个帖子写的，下面的图片也截自这里
`https://leetcode.com/problems/maximum-of-absolute-value-expression/discuss/339968/JavaC%2B%2BPython-Maximum-Manhattan-Distance`

![image.png](https://pic.leetcode-cn.com/0817a48aba3d6240ec0737ddbc661ac727e48175c9b7bf745a08093696665350-image.png)
![image.png](https://pic.leetcode-cn.com/c6f69ea8597c949f0b96ec00a0c1b99be381aa4a76dd4dc31ee81b5e4011e10d-image.png)
![image.png](https://pic.leetcode-cn.com/1dfc2ce8afed9a87c5aae541fb568fb99148f8d3f28db28a1650467bf4c89e9f-image.png)
![image.png](https://pic.leetcode-cn.com/bc8c7aa74463770c7a057a38fecc53a4e2cf1e0e031f04bbedd5172231ab6f0b-image.png)
![image.png](https://pic.leetcode-cn.com/3f2cd5a1b6f566ec9a168fe85c1fbd9d9393fcd5feeaed40edd06347f3dee427-image.png)
![image.png](https://pic.leetcode-cn.com/ffc8976344b8726c0e211141ea08fb1370696585bdfa32244fe770d98d15230d-image.png)
![image.png](https://pic.leetcode-cn.com/fb4d720586808996a71fa9b9470f150bf47beb93118d1bbad14f66d13d3e9ba3-image.png)
![image.png](https://pic.leetcode-cn.com/003ab08097fc60b9afc1f53c2008083891bada251f42583d54b212c26b69e3ae-image.png)
![image.png](https://pic.leetcode-cn.com/5d2eb4c54bdb2edf1323081ed8d7143ff5866dca0dfc53ef9266ddb0225a02d8-image.png)
![image.png](https://pic.leetcode-cn.com/35e8373071527754ea953c67208ba0b5354acb1f6a3ef7a0a0343822162653e6-image.png)

看完这个才觉得这个题跟曼哈顿距离有关系
![image.png](https://pic.leetcode-cn.com/9e2dfd36c1f16a5c79465ae3708a9954be5fe3d7ccb556d8031c1ae208e93938-image.png)
下面的四角思维就是根据上面划线那里得出来的


![image.png](https://pic.leetcode-cn.com/83f5b0d1c803880304df6959aff1796044bf66fcb6f45d16a34e04cb6cd355c3-image.png)
![image.png](https://pic.leetcode-cn.com/a47bd16559e4fe2e48f5671a021d1a97b0d50fb4c94a5a4ebb2c969a9b8a6c4c-image.png)

我就理解了这个四角思维，还没理解这个四向思维，下面代码是八个角(没理解上面那里为什么`+i`,就干掉了`|i-j|`,有人说是因为`i<j`,？？？))
![image.png](https://pic.leetcode-cn.com/118796fb5b7b79c3ecccc65ec7be2559c44794252dac619f89cc0c4146ee5098-image.png)

![image.png](https://pic.leetcode-cn.com/cee9bd19ea12375ed29877aeaed22d120a33da5299445e6637ae7020b3cbbeff-image.png)



### 代码

```cpp
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        vector<int>maxs(8, -INT_MAX);
        vector<int>mins(8, INT_MAX);
        int MAX = 1000000+1;
        int corner[8][3] = {{MAX,  MAX, MAX},
                            {MAX, -MAX, MAX},
                            {MAX,  MAX, MAX},
                            {MAX, -MAX, -MAX},
                            {-MAX, -MAX, -MAX},
                            {-MAX, -MAX, MAX},
                            {-MAX, MAX, -MAX},
                            {-MAX, MAX, MAX}};  //8个角落
        for(int k = 0; k < 8; k++)
        {
            for(int i = 0; i < arr1.size(); i++)
            {
                maxs[k] = max( maxs[k], abs(corner[k][0]-arr1[i]) + abs(corner[k][1] - arr2[i])+abs(corner[k][2] -i));
                mins[k] = min( mins[k], abs(corner[k][0]-arr1[i]) + abs(corner[k][1] - arr2[i])+abs(corner[k][2] -i));
            }
        }
        int res = -INT_MAX;
        for(int i = 0; i < 8; i++)
        {
            res = max(res, maxs[i]-mins[i]);
        }
        return res;
    }
};
```