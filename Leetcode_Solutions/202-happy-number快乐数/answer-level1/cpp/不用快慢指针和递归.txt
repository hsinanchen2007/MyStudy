### 解题思路
经验证：在小于10的数字中，只有1和7是快乐数，其他都不是。
所以可以把条件设成 "n>=10"
然后循环数字即可。

可以用vector或者数组存放平方数以缩短求平方的时间，
不过放不放对时间和内存消耗貌似都没有影响，击败数还是一样。

![image.png](https://pic.leetcode-cn.com/9f9c31c15c8b8512e25bc45dd2c0f6dbb3b085092e1ee5fdb8d7cc3879a11794-image.png)


### 代码

```cpp
class Solution {
public:
//  小于10的数中，只有1和7是快乐数
    bool isHappy(int n) {   // by me
        int sum = 0;
        while(n>=10){
            while(n!=0){
                sum += ((n%10)*(n%10));
                n /= 10;
            }
            n = sum;
            sum = 0;
        }

        if(n!=1 && n!=7) return 0;

        return 1;
    }
};
```

```cpp
class Solution {
public:
//  小于10的数中，只有1和7是快乐数
    bool isHappy(int n) {   // by me
        vector<int> ivec{0,1,4,9,16,25,36,49,64,81};
        int sum = 0;
        while(n>=10){
            while(n!=0){
                sum += ivec[n%10];
                n /= 10;
            }
            n = sum;
            sum = 0;
        }

        if(n!=1 && n!=7) return 0;

        return 1;
    }
};
```