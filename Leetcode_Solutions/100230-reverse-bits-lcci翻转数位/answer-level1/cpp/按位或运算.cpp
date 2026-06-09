### 解题思路
看到这题很容易想到状压常用操作，**把一个数x右起第一个0变为1只需要x|(x+1)即可**，然后数一下右起的1的个数，更新一下答案，然后把原来的x右边连续的1去掉，继续下去即可，特判一下0以及开long long就好了（有个数据是2^31-1，这时加一就炸了）。
![image.png](https://pic.leetcode-cn.com/ddbee8187da241d0cc77832ad2802eec87f5c5b8b2020ee83406afd74a9b7863-image.png)


### 代码

```cpp
class Solution {
public:
    int cal(long long x){
        int ans=0;
        while(x&1){
            ++ans;
            x>>=1;
        }
        return ans;
    }
    int reverseBits(long long num) {
        if(num==0) return 1;
        int cnt=0;
        while(num){
            cnt=max(cnt,cal(num|(num+1)));
            num>>=cal(num)+1;
        }
        return cnt;
    }
};
```