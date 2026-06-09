### 解题思路
和s+s在find的方法没得比，但是如果要你 找出重复的字符串，我这种方法就能派的上用场

### 代码

```cpp
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        int index = 1;
        while(index < size/2 + 1){
            if(s[index] == s[0]){
                int templow = 0;
                int temphigh = index;
                int count = 0;
                while(temphigh < size){
                    if(s[templow] == s[temphigh]){
                        temphigh++;
                        templow++;
                        count++;
                    }
                    else
                        break;
                }
                if(temphigh == size && count%index == 0)
                    return true;
            }
            index++;
        }
        return false;
    }
};
```