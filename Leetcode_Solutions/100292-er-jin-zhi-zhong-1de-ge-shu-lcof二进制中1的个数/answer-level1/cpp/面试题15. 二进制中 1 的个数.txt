方法一
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n>0){
            if(n%2) res++;
            n /=2;
        }
        return res;
    }
};
```
方法二 
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n>0){
        res += n & 1;
        n >>= 1;
        }
        return res;
    }
};
```
方法三 
n-1将n的二进制最右边的1变为0，最右边1右边0变为1
n&(n-1)消除n的二进制最右边的1
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n>0){
            res += 1;
            n &= n-1;
        }
        return res;
    }
};
```

