### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> mp;
        int s=0;
        int e=0;
        string ss;
        bool fla=true;
        for(int i=0;i<paragraph.size();i++){
            if(paragraph[i]>='A'&&paragraph[i]<='Z')paragraph[i]=paragraph[i]-'A'+'a';
            if(isal(paragraph[i])==true){
                fla=true;
                ss+=paragraph[i];
            }
            if(fla==true&&(isal(paragraph[i])==false||i==paragraph.size()-1)){
                fla=false;
                bool flag=true;
                for(int k=0;k<banned.size();k++){
                    if(ss==banned[k]){
                        flag=false;
                    }
                }
                if(flag==true)
                    mp[ss]++;
                ss="";
            }
        }
        string ans;
        int max1=-1;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(max1<it->second){
                max1=it->second;
                ans=it->first;
            }
        }
        return ans;
    }
    bool isal(char ch){
        if((ch>='a'&&ch<='z')){
            return true;
        }
        return false;
    }
};
```