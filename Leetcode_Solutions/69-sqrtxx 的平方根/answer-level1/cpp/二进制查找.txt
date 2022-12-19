### 解题思路
对于比较大的数，用二进制的查找理论上会缩减时间，不过这里执行效率并不好..后面其实应该用二分查找的
看到其他题解一是通过一个数的平方根<其二分之一压缩范围，再通过二分查找。

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){
            return x;
        }
        long temp = 1;
        int i = 0;
        while(temp<x){
            temp = temp<<1;
            i++;
        }
        i--;
        int j = pow(2,i/2);
        for(;j<x;j++){
            long y = pow(j,2);
            if(y<x) continue;
            else if(y>x) break;
            else return j;
        }
        return j-1;
    }
};

```
确定范围后采用二分查找，效果好多了
```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x==0||x==1){
            return x;
        }
        long temp = 1;
        int i = 0;
        while(temp<x){
            temp = temp<<1;
            i++;
        }
        i--;
        int left = pow(2,i/2);
        int right = x/2;
        while (left<=right) {
            int mid = (left+right)/2;
            if(pow(mid,2)>x){
                right = mid - 1;
            }
            else if (pow(mid,1)<x){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }
        return right;
    }
};
```