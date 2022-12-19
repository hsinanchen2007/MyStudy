### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution { //左右遍历 求乘积
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int>  ans(n);
        int tmp = 1;
        for(int i = 0; i < a.size(); ++i){//对于最左元素 左侧无 故tmp=1 
            ans[i] = tmp;//先赋值再乘积 使得B[i]=A[0]*..A[i-1]
            tmp *= a[i];
        }
        tmp = 1;
        for(int i = n-1; i >= 0; --i){
            ans[i] *= tmp;//先赋值再乘积 使得B[i]=A[i+1]...A[n-1]
            tmp *= a[i];
        }
        return ans;
    }
};


```