### 解题思路
![TIM截图20200319152238.png](https://pic.leetcode-cn.com/c09167ddec31be0490303bc176024eca552d55d36c2a496dc190f48c7a0195c4-TIM%E6%88%AA%E5%9B%BE20200319152238.png)
1.首先判断n是否是质数，若是质数则只能一次一次复制直到n，总共按键n次。
2.若不是质数，找n的最大因子len。
3.达到n的按键次数等于达到len的按键，再多按 n/len次，即复制一次，粘贴n/len-1次。
### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
        if(n == 1) return 0;
        if(isprim(n)) return n;
        int len;
        if(n % 2 == 0){
            len = n / 2;
        }else{
            len = findMaxFactor(n);
        }
        int i, j;
        return minSteps(len) + n / len;
    }

    bool isprim(int n){
        if(n <= 3) return true;
        for(int i = 2; i < n ; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

    int findMaxFactor(int n){
        int max = 0;
        for(int i = 3; i < n; i++){
            if(n % i == 0) max = (i > max)? i : max;
        }
        return max;
    }

};
```