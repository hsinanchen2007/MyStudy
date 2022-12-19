### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.length()==0&&b.length()==0){
            return -1;
        }
        if(a==b){
            return -1;
        }
        if(a.length()<b.length()){
            string temp=a;
            a=b;
            b=temp;
        }
        
        return a.length();
    }
};
```