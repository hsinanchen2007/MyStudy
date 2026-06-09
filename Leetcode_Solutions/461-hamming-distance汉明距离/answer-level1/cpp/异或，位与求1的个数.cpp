### 解题思路
此处撰写解题思路
求1的个数：(两种思路)
1.不断该数减一按位与直到0;
2.定义一个count，将该数不断和1异或，判断最后一位的0-1情况

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=x^y;
        int count=0;
        while(res){
            res=res&(res-1);
            count++;
        }
        return count;
    }
};
```