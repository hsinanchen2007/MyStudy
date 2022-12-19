### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>hashTable(30);
        for(auto c:chars){
            hashTable[c-'a']++;
        }
        int sum=0;
        for(int i=0;i<words.size();i++){
            vector<int>temp=hashTable;
            int L=words[i].size();
            bool flag=true;
            for(int j=0;j<words[i].size();j++){
                temp[words[i][j]-'a']--;
            }
            for(auto it:temp){
                if(it<0){
                    flag=false;
                    break;
                }
            }
            if(flag){
                sum+=L;
            }
        }
        return sum;
    }
};
```