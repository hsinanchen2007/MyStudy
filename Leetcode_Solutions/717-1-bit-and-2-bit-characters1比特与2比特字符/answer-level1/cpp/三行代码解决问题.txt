### 解题思路
最后一位是0，最后有可能是10或者0，只要有1出现，就要判断是不是10，直接看最后一个0前面有几个连续的1就好，奇数个，最后就是10，偶数个，那一坨1就都是11，最后就是单0

### 代码

```cpp
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
		int sum=0,i=bits.size()-2;
		while(i>=0&&bits[i]==1) {++sum;--i;}
		return sum%2==0;
    }
};
```