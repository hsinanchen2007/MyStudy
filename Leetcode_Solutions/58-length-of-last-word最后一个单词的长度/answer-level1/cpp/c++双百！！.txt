![捕获.PNG](https://pic.leetcode-cn.com/c8f70ffb3f4ce5ca73df0c2828054b7db73843019ada6bd7f6088cdee0ece2a8-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int size=0;
        for(auto iter=s.rbegin();iter!=s.rend();++iter){
            if(!isspace(*iter))
                ++size;
            else {
                if(size==0)
                    continue;
                else
                    break;
            }
        }
        return size;
    }
};
```
