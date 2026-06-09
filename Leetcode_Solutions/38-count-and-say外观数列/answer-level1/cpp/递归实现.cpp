### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string last = countAndSay(n-1);
        string creatString;
        int len = last.length();
        
        int count=1;
        char s=last[0];
        for(int i = 0;i<len;i++){
            if(s == last[i+1]){
                count ++;
            }
            else{
               creatString.push_back(count+'0'); 
               creatString.push_back(s); 
               count = 1;
            }
            s = last[i+1];
        }
        return creatString;
    }
};
```