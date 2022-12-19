![image.png](https://pic.leetcode-cn.com/f9219adaf252a125e14e6e5130ae8e18a232e4a804412cf5666caea98a320804-image.png)
分割数组只需要左边的值全部都小于或等于右边的值，转换一下，也就是要**左边部分的最大值小于等于右边部分的最小值**，用数组A,B分别记录下每个位置**左边部分的最大值**与**右边部分的最小值**，然后找到一个A[i]<=B[i+1]即是所求。
# 例如：[5,0,3,8,6]
# 得到：
# A:  5 5 5 8 8 
# B:  0 0 3 6 6 
# 返回：3
```
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        if(A.size()<=1) return 0;
        vector<int>B(A);
        for(int i=1;i<A.size();i++){
            if(A[i]<A[i-1]) A[i]=A[i-1];
            if(B[B.size()-1-i]>B[B.size()-i]) B[B.size()-1-i]=B[B.size()-i];
            }
        for(int i=0;i<A.size()-1;i++){
            if(A[i]<=B[i+1]) return i+1;
        }
        return A.size();
    }
};
```
