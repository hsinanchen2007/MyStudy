### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/b00ddd68209eb124f55ef0d8b72ff8cec74021ec25b8a48151fd42b5849bd3d6-image.png)

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=x^y;
        int res=0;
        while(ans!=0){
            ans=ans&(ans-1);
            res++;
        }
        return res;
    }
};
```