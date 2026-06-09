### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ch[26]={0};
        for(char c:chars)
            ch[c-'a']++;
        int len=0;
        for(int i=0;i<words.size();i++){
            int tmp[26]={0};
            bool flag=false;
            memcpy(tmp,ch,sizeof(ch));
            for(char w:words[i])
                if(tmp[w-'a']==0){
                    flag=true;
                    break;
                }
                else
                    tmp[w-'a']--;
            if(!flag)
                len+=words[i].size();
        }
        return len;
                
    }
};
```