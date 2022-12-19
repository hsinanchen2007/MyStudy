
如果代码写多了，越来越懒，说明写了很多没有那么有趣的代码。散发着铜臭味的代码。

```
class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        vector<int>a,b;
        int l = 0;
        for(int i=0;i<version1.length();i++){
            if(version1[i] == '.'){
                int tmp = stoi(version1.substr(l,i));
                a.push_back(tmp);
                l = i+1;
            }
        }
        a.push_back(stoi(version1.substr(l,version1.length())));
        l = 0;
        for(int i=0;i<version2.length();i++){
            if(version2[i] == '.'){
                int tmp = stoi(version2.substr(l,i));
                b.push_back(tmp);
                l = i+1;
            }
        }
        b.push_back(stoi(version2.substr(l,version2.length())));

        while(a.size() < b.size()){
            a.push_back(0);
        }
        while(b.size() < a.size()){
            b.push_back(0);
        }
        int cmp = 0;
        for(int i=0;i<a.size();i++){
            if(a[i] < b[i]){
                cmp = -1;break;
            }
             if(a[i] > b[i]){
                cmp = 1;break;
            }
        }
        return cmp;
        
    }
};
```
