### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
        return 0;
        bool a[n];
        int count=0;
        for(int i=2;i<n;i++)
        a[i]=true;
        for(long i=2;i<n;i++){
            if(a[i])
            for(long j=i*i;j<n;j+=i)
            a[j]=false;
        }
        for(int i=2;i<n;i++)
        if(true==a[i])
        count++;
        return count;
    }
};
```