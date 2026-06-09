### 解题思路
原数组是从小到大排序，但是因为有正与负所以不能直接平方，于是我们需要先找到中间的数字，即第一个正数或者0。这个中间数字的下标为i，A[i]w为当前备选的最小平方数字之一，而另一个备选的最小平方数字即为A[j],j=i-1。
每次比较A[i]和-A[j]的大小，将小的数的平方插入结果向量，而后只需将i,j往两边扩展即可.

### 代码

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        int i,j;
        for(i = 0;i < A.size() && A[i] < 0;i++);
        j = i-1;
        while(j>=0 && i < A.size()){
            if(A[i] < 0-A[j]){
                res.push_back(A[i]*A[i]);
                i++;
            }
            else{
                res.push_back(A[j]*A[j]);
                j--;
            }
        }
        while(j >= 0){
            res.push_back(A[j]*A[j]);
            j--;
        }
        while(i < A.size()){
            res.push_back(A[i]*A[i]);
                i++;
        }
        return res;
    }
};
```