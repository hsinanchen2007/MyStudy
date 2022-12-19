### 解题思路
使用两个辅助数组x与y
- x[i]记录A[0]×A[1]×…×A[i-1]
- y[i]记录A[i+1]×A[i+2]×…×A[n-1]
- res[i]=x[i]×y[i]

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n=a.size();
        vector<int> res;
        if(n==0)
            return res;
        int x[n],y[n];
        for(int i=0;i<n;i++)
            if(i==0){
                x[i]=1;
                y[n-1-i]=1;
            }
            else{
                x[i]=x[i-1]*a[i-1];
                y[n-1-i]=y[n-i]*a[n-i];
            }
        for(int i=0;i<n;i++)
            res.push_back(x[i]*y[i]);
        return res;
    }
};
```