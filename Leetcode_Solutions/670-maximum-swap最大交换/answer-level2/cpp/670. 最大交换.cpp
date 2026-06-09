### 解题思路
双100%
从最高位i开始
从最低位开始找比num[i]大的数字
### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        if(num<12) return num;
        string s=to_string(num);
        int id;
        char n; 
        for(int i=0;i<s.size();i++){
            n=s[i];id=i;
            for(int j=s.size()-1;j>i;j--){
                if(s[j]>n){
                    id=j;n=s[j];
                }
            }
            if(id!=i){
                swap(s[i],s[id]);
                return stoi(s);
            }
        }
        return num;
    }
};
```