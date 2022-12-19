### 解题思路
用hashmap做缓存，快速查找
![WX20200322-183330.png](https://pic.leetcode-cn.com/dbdc07af70c77d74083a299cdf39eee8e28ac13ee53e3e6a98028facfb7196f1-WX20200322-183330.png)


### 代码

```cpp
class Solution {
public:
    bool confusingNumber(int N) {
        int old = N;
        int reverse = 0;
        unordered_map<int,int> m = {{6,9},{9,6},{8,8},{0,0},{1,1}};
        while(N){
            if(m.find(N%10) == m.end())
                return false;
            reverse = reverse*10 + m[N%10];
            N /= 10;
        }

        return reverse != old;
    }
};
```