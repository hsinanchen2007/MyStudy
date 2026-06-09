### 代码

```cpp
class Solution {
public:
    string sortString(string s) {
        vector<int> vec(26,0);
        for(int i=0;i<s.size();++i){
            ++vec[s[i]-'a'];
        }
        int vecsize=vec.size();
        int count=s.size();
        string res="";
        while(count){
            for(int i=0;i<vecsize;++i){
                if(vec[i]>0){
                    res+=i+'a';
                    --vec[i];
                    --count;
                }
            }
            for(int i=vecsize-1;i>=0;--i){
                if(vec[i]>0){
                    res+=i+'a';
                    --vec[i];
                    --count;
                }
            }
        }
        return res;
    }
};
```