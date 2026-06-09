
![批注 2020-01-28 153113.png](https://pic.leetcode-cn.com/e389a47dc0f2f86796f604bfd7d0930393b7008b6313c8f2ae9eca77ae26cb8b-%E6%89%B9%E6%B3%A8%202020-01-28%20153113.png)
### 解题思路
- p指针作为偶指针，只检查偶数位是否满足条件，同理q指针作为奇指针。奇偶指针按步数2移动。
- 在满足pq指针都不超过数组范围的条件下，依次寻找下一个不满足的偶数位和奇数位，交换这两个元素。
### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int p=0, q=1;
        while(p<A.size()&&q<A.size()){
            while(A[p]%2==0&&p+2<A.size()){
                p+=2;
            }
            while(A[q]%2!=0&&q+2<A.size()){
                q+=2;
            }
            if(A[p]%2!=0&&A[q]%2==0){
                swap(A[p], A[q]);
            }
            p+=2;
            q+=2;
        }
        return A;
    }
};
```