```C++ []
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int temp=0;
        while(n){
            temp+=n&1;
            n>>=1;
        }
        return temp;
    }
};
```
```python3 []
class Solution:
    def hammingWeight(self, n: int) -> int:
        temp=0
        while n:
            temp+=n&1
            n>>=1
        return temp
```
```C []
int hammingWeight(uint32_t n) {
    int temp=0;
    while(n){
        temp+=n&1;
        n>>=1;
    }
    return temp;
}
```
```Python []
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        temp=0
        while n:
            temp+=n&1
            n>>=1
        return temp
```
```Java []
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int temp=0;
        while(n!=0){
            temp+=n&1;
            n>>>=1;
        }
        return temp;
    }
}
```
```JavaScript []
function hammingWeight(n) {
    var temp=0;
    while(n){
        temp+=n&1;
        n>>>=1;
    }
    return temp;
}
```