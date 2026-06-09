### 解题思路
从后往前找最大的6 然后加上shift让6变成9

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        int len=0;
        int n=num;
        int c;
        int shift=0;
        while (n){
            c=n%10; // last_number
            n=n/10;
            if (c==6){
                shift=3*pow(10,len);
            }
            len++;
        }
        return num+shift;
    }
};
```