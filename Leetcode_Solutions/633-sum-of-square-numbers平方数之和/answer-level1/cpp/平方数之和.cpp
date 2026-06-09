### 解题思路
双指针，为防止加法溢出，条件判断写为i*i<c-j*j

### 代码

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
       int i=0,j=sqrt(c);
       while(i<=j){
           if(i*i<c-j*j) i++;
           else if(i*i>c-j*j) j--;
           else return true;
       }
       return false;
    }
};
```