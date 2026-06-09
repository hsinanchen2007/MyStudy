### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int binaryGap(int N) {
        int index1 = 33;
        int count = 0;
        int maxDis = 0;
        while(N){
            count++;
            if(N%2){
                maxDis = max(maxDis, count-index1);
                index1 = count;
            }
            N /= 2;
        }
        return maxDis;
    }
};
```