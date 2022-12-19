```
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray(1<<n);
        help(gray,n);
        return gray;
    }
    void help(vector<int>&gray,int n)
        {
            if(n==0)return;
            help(gray,n-1);
            for(int i=1<<(n-1);i<1<<n;i++)
            {
                gray[i]+=(1<<(n-1))+gray[(1<<n)-1-i];
            }
        }
};
```
题目描述就不说了，前面的答案都有说，分享一种递归的解法。
第一点是考虑如何将高维数据转低维，这也是递归的第一步。设Gray(n)是格雷码的n阶排列，那么它的镜像Gray'(n)（即将所有元素倒序）也是一种伪格雷码序列（不满足起始点为0）。在Gray(n)的每个元素前补一个0，Gray'(n)每个元素前补1，再将他们连接即可获得Gray(n+1)。
第二点是考虑如何将生成整数序列。由于每次补1相当于加上2的n-1次方，且只对序列的后半部分操作，因此这里可以用循环实现数据累加。