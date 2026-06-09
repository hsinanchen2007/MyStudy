### 解题思路
不允许使用除法，首先暴力解超出了时间限制，借鉴题解区的大佬，建立关于数左右乘积的数组，使用了动态规划，得到结果就是左右数组之积。

### 代码

```cpp
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        /*
        int len=a.size();
        vector<int> res(len,1);
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(i!=j){
                    res[i] *= a[j]; 
                }
            }
        }
        return res;
        */
        int len =a.size();
        vector<int> left(len,1);
        vector<int> right(len,1);
        for(int i=1;i<len;i++){
            left[i]=left[i-1]*a[i-1];
        }
        for(int i=len-2;i>-1;i--){
            right[i]=right[i+1]*a[i+1];
        }
        for(int i=0;i<len;i++){
            a[i]=left[i]*right[i];
        }
        return a;
    }

};
```