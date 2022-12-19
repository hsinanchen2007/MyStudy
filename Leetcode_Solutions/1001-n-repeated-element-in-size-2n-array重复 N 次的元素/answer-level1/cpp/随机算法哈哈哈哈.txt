### 解题思路
随机，抽俩元素，如果一样那这个数就是所求，循环20次，基本很大概率能抽中哈哈哈哈，刷出来最好的一次是20ms

### 代码

```cpp
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {

        for(int i=0; i<20; i++){
            srand(time(0)+i*12434);
            int q=rand()%A.size();
            srand(time(0)+i*12434+43254);
            int c=rand()%A.size();
            if(A[q]==A[c] && q!=c)
                return A[q];
        }
        return -1;
    }
};
```