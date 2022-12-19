### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool checkRecord(string s) {
        int countA = 0;
        int countL = 0;
        for(char c : s){
            if(c == 'A'){
                countA++;
                if(countA>1)
                    return false;
                    countL = 0;
            }
            else if(c == 'L'){
                countL++;
                if(countL > 2)
                    return false;
            }
            else
                countL = 0;
        }
        return true;
    }
};
```