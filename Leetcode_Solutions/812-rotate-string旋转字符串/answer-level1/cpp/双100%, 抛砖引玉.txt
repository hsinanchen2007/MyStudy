### 解题思路
首先判断两个字符串长度是否相同；
然后固定b字符串，遍历a的所有字符;
    当a[i]==b[0]时，进入第一个循环:逐字符比对到字符串尾部；
    进入第二个循环：从a[0]开始与b[size-i]比对，如果一直到i全部相同，则为true.


### 代码

```cpp
class Solution {
public:
bool rotateString(string a, string b) {
    if(a.size() != b .size()) return false;
    if(a == "" && b == "") return true;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[0]){
            int j;
            for(j = i+1; j<a.size(); j++){
                if(a[j] != b[j-i]){break;}
            }
            if(j != a.size()) continue;
            for(j = 0; j<i; j++){
                if(a[j] != b[a.size()-i+j]){
                    break;
                }
            }
            if( j != i){continue;}
            else{return true;}
        }
    }
    return false;
}
};
```