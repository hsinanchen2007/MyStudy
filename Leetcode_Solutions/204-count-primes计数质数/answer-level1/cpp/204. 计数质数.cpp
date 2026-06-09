## 求质数
**求质数的模板！**
```cpp
class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        bool notPrime[n] = { false };//哈希表
        int cnt=0;
        for(int i=2; i<n; i++){
            if(notPrime[i]==false){
                cnt++;
                for(int j=i+i; j<n; j+=i){ //细节
                    notPrime[j] = true;
                }
            }
        }
        return cnt;
    }
};
```
![image.png](https://pic.leetcode-cn.com/23d348bef930ca4bb73f749500f664ccffc5e41467aac0ba9787025392ca207b-1.gif)
*图片偷来的，只为做笔记，侵删*

