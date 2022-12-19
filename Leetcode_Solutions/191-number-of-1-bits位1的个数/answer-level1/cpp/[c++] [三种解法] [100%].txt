### 解题思路
![image.png](https://pic.leetcode-cn.com/013ca52c9abdcb39a8a01d91dd4274080205a63067341c5c5776bf09ec95d6ad-image.png)

### 代码
解法一：
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            if(n&1){
                cnt++;
            }
            n>>=1;
        }
        return cnt;
    }
};

```
解法二：[100%]
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        uint32_t flag=1;
        while(flag){
            if(n&flag){
                cnt++;
            }
            flag<<=1;
        }
        return cnt;
    }
};
```

解法三：
```cpp
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};
```