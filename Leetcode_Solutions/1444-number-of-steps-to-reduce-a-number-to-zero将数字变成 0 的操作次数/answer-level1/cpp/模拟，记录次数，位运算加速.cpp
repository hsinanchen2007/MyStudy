```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int i;
        for(i=0;num;++i){
            if(num&1) num^=1;
            else num>>=1;
        }
        return i;
    }
};
```
总结规律，发现直接移位就行，最低位是1就多记一次数，注意最后一次会多记一次，因为已经不需要移位，所以最后结果需要-1
```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int i;
        for(i=0;num;num>>=1){
            if(num&1) i+=2;
            else ++i;
        }
        return --i;
    }
};
```
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.1 MB, 在所有 C++ 提交中击败了100.00%的用户
