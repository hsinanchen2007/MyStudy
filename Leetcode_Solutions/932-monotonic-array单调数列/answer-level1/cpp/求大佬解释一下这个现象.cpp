### 返回值的类型会影响程序的效率吗？int类型的反而更快？
```
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        int flag1 = 0;
        int flag2 = 0;
        for(int i = 1; i < len; i++){
            if(A[i-1] > A[i]){
                flag1 = 1;
            }
            if(A[i-1] < A[i]){
                flag2 = 1;
            }
        }
        return !(flag1 && flag2);
    }
};
```
![1.png](https://pic.leetcode-cn.com/b8b1bb873462b0d65fca938eec9aaed5cc02fffc4213567cb8bad38de895d839-1.png)

```
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();
        bool flag1 = false;
        bool flag2 = false;
        for(int i = 1; i < len; i++){
            if(A[i-1] > A[i]){
                flag1 = true;
            }
            if(A[i-1] < A[i]){
                flag2 = true;
            }
        }
        return !(flag1 && flag2);
    }
};
```
![2.png](https://pic.leetcode-cn.com/c39b601d17ea58b4a8b0b039132f843921610c464548ccb23ee13cef0d166b46-2.png)

