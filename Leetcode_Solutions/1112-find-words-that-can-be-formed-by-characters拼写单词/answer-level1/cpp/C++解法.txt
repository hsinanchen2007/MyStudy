### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int flag = 0;
        int res =0;
        for(int i = 0;i < words.size();i++){
            string tmp = chars;
            for(int j =0; j<words[i].size();j++){
                flag=0;
                for(int k=0; k<chars.size();k++){
                    if(words[i][j] == tmp[k]){
                        tmp.erase(k, 1);
                        flag = 1;
                        cout<<words[i][j]<<endl;
                        break;
                    }
                }
                    
                if(flag==0)
                break;
            }
            cout<<flag<<endl;
            if(flag)
                res += words[i].size();
        }
        return res;
    }
};
```