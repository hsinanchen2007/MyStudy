### 解题思路
将每个数字出现的次数存入一个新的数组中，遍历存储次数的数组，减去数值使数组中数字只能为0或1，减去的数值总和即为操作次数。

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<2)return 0;
        int count=0,maxsize=0;
        int a[80000]={0};
        for(int num:A){
            a[num]++;
            maxsize=max(maxsize,num);
        }
        for(int i=0;i<=maxsize+a[maxsize];i++){
            if(a[i]>1){
                count+=(a[i]-1);
                a[i+1]+=(a[i]-1);
            }
        }
        return count;
    }
};
```