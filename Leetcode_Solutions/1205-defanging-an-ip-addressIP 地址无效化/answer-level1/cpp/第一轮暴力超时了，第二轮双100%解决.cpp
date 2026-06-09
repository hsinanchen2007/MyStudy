主要思路是，‘.’只在固定位置出现，出现的规律为与标志位（初始为0）差1~3位，逐步判断找出该位置，在该位置前后加[]即可。最后标志位应是‘.’后一位再加上插入的[]所以为 +3.

```
class Solution {
public:
    string defangIPaddr(string address) {
        int i = 0,s;
        for(int j=0; j <= 2; ++j) {
        s = i+1;
        if(address[s] == '.') {
            i = s;
        } else if(address[s+1] == '.') {
            i = s+1;
        } else {
            i = s+2;
        }
        address.insert(i, "[");
        address.insert(i+2, "]");
        i+=3;
        }
        return address;
    }
};
```