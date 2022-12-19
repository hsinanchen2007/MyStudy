### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1;
        vector<string> v2;

        int i=0;
        int j=0;
        string cur;
        while(i<version1.length()){
            if(version1[i]!='.') {
                cur+=version1[i];
                i++;
                continue;
            }
            else{
                v1.push_back(cur);
                j++;
                i++;
                cur.clear();
            }           
        }
        v1.push_back(cur);       

        
        i=0;
        j=0;
        cur.clear();
        while(i<version2.length()){
            if(version2[i]!='.') {
                cur+=version2[i];
                i++;
                continue;
            }
            else{
                v2.push_back(cur);
                j++;
                i++;
                cur.clear();
            }           
        }
        v2.push_back(cur);
        int size=max(v1.size(),v2.size());
        for(int p=v1.size();p<size;p++){
            v1.push_back("0");
        }
        for(int p=v2.size();p<size;p++){
            v2.push_back("0");
        }

        int m=0,n=0;
        for(int i=0;i<size;i++){
            m=0;
            for(int k=0;k<v1[i].length();k++){
                m+=m*10+v1[i][k]-'0';
            }
            n=0;
            for(int k=0;k<v2[i].length();k++){
                n+=n*10+v2[i][k]-'0';
            }
            if(m<n){
                return -1;
                break;
            }
            if(m>n){
                return 1;
                break;
            }
            if(m==n);            
        }
        return 0;  
    }
};
```