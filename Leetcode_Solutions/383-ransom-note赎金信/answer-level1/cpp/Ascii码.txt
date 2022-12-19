### 解题思路
此处撰写解题思路
开始想成了KMP，写了一会发现想错题意了。
### 代码

```cpp
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int length1=ransomNote.length();
        int length2=magazine.length();
        if(length1>length2){
            return false;
        }
        if(length1==0){
            return true;
        }
        int s[26]={0};
        for(int i=0;i<length2;i++){
            s[magazine[i]-'a']+=1;
        }
        for(int j=0;j<length1;j++){
            s[ransomNote[j]-'a']-=1;
        }
        for(int i=0;i<26;i++){
            if(s[i]<0){
                return false;
            }
        }
        return true;
        
    }
};
```