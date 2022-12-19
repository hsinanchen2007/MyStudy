### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numSteps(string s) {
        int i = s.size()-1;
        int count  = 0;
        while(i>=1){
            if(s[i] == '0'){
                count++;
                i--;
            }
            else if(s[i] == '1'){
                int j = i;
                while(j>=0){
                    
                    if(s[j] == '1'){
                        s[j] = '0';
                        if(j == 0){
                            count += 1+i;
                            i = -1;
                            break;
                        }
                        j--;
                    }
                    else if(s[j] == '0'){
                        s[j] = '1';
                        break;
                    }
                }
                count++;
            }
        }
        return count;
    }      
};
```