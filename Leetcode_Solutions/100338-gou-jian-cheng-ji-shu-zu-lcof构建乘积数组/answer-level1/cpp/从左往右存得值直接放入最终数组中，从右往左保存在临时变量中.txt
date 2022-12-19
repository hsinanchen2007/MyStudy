```
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n = A.size();
        vector <int> b(n);
        int temp = 1;
        for (int i = 0; i < n; i++){
            b[i] = temp;//如果要累乘的话需要把内容初始化为1
            temp *= A[i];//这样先赋值，在对i进行累乘，可以使a[i]不被乘进去
            //把所有左边的都乘进数组里了，用temp不重复计算！！利用上次的值！！
        }
        temp = 1; //重新清零
        for (int i = n - 1;i >= 0; --i){
            b[i] *= temp;//之前b[]还是个半成品
            temp *= A[i];
        }
        return b;
    }
    
};
```
