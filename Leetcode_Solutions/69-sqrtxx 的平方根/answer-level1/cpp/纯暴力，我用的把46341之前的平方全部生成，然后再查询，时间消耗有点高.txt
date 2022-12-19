### 解题思路
此处撰写解题思路
为什么是46341呢，是因为46342的平方已经超过INT_MAX了
### 代码

```cpp
const int N=46341;
int book[N]={0};
class Solution {
public:
    int mySqrt(int x) {
        if(book[1]==0){
            for(int i=0;i<N;i++){
            book[i]=i*i;
            }
        }
        for(int i=0;i<N;i++){
            if(book[i]==x){
                return i;
            }
            if(book[i]>x){
                return i-1;
            }
        }
        return N-1;
    }
};
```