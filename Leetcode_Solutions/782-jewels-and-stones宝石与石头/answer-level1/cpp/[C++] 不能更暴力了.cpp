### 解题思路
思路很简单，对J中的每一项，遍历S的每一项，若有相同则除去S中对应项。
为了实现“除去操作”，第二层for循环使用string::iterator和erase()方法。

特殊处理：执行erase()方法后，需要将迭代器移向前一项，否则会出现漏项。

### 代码

```cpp
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int rst = 0;
        for(int i = 0; i < J.length(); i++){
            string::iterator it;
            for(it = S.begin(); ; it++){
                if(*it == J[i]){
                    S.erase(it);
                    rst++;
                    it--;
                }
                if(it == S.end()) break;
            }
        }
        return rst;
    }
};
```