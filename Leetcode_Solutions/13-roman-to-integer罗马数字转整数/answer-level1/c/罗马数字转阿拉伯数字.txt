### 解题思路
解题的关键在于扫描到的字符和它后一个字符之间的关系，如果这个字符的权重比后面那个字符小，就减去它的权值，否则加上它的权值

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {     
        char key[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int value[] = {1,   5,   10,  50, 100, 500, 1000};
        int ret = 0;
        int value_length = sizeof(value) / sizeof(value[0]);
        for(int i = 0; i < s.size()-1; i++){
            for(int j = 0; j < value_length; j++){
                if(s[i] != key[j]){   
                    continue;
                }
                int k = 0;
                for(; k < value_length; k++){
                    if(s[i+1] == key[k]){
                        break;
                    }
                }
                if(value[j] < value[k]){
                    ret -= value[j]; 
                }else{
                    ret += value[j];
                }
            }
        }
        for(int i = 0; i < value_length; i++){
            if(s[s.size()-1] == key[i]){
                ret += value[i];
            }
        }
        return ret;
    }
};
```