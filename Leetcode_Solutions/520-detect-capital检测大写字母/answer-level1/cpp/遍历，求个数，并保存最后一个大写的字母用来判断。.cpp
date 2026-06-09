### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int length=word.length();
        int count=0;
        int flag=false;
        int s=0;
        for(int i=0;i<length;i++){
            if(word[i] <='Z' && word[i] >='A' ){
                count++;
                s=i;
            }
        }
        if(count==0 || count==length ){
            return true;
        }else{
            return s==0?true:false;
        }
        return flag;
    }
};
```