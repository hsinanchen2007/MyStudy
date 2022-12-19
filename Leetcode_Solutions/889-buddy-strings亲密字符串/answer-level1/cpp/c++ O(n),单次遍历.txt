### 解题思路
三种情况：
+ 若A和B长度不等，直接返回false
+ 若A和B完全相同，判断A中是否有重复出现的字母。unordered_set的插入和查找都是O（1）
+ 若不完全相同 找到第一次和第二次不同的下标，交换后判断两字符串是否相等

### 代码

```cpp
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A == B){
            unordered_set<char> se;
            for(auto c: A){
                if(se.count(c)) return true;
                se.insert(c);
            }
        }
        int cnt = 0;
        int pos;
        for(int i = 0; i < A.size(); i++){
            if(A[i] != B[i]){
                if(cnt == 0){
                    pos = i;
                    cnt++;
                }
                else if(cnt == 1){
                    swap(A[i], A[pos]);
                    return A == B;
                }
            }
        }
        return false;
    }
};
```