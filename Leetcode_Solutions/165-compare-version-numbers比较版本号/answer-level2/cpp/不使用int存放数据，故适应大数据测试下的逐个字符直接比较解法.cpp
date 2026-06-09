 `c++`   看见很多人直接用int存放，那么这在大数据环境下很可能会溢出...这里给出一种逐个比较字符的解法，适应大数据，但显得比较繁琐，没有优化，望见谅！希望有更加优化的版本

```c++
class Solution {
public:
    int compareVersion(string version1, string version2) {
        string t = version1;
        bool f = false;
        if(version1.size() < version2.size()){
            version1 = version2;
            f = true;
        }
        version2 = t.size() < version2.size() ? t : version2;
        int v1 = 0,v2 = 0;
        while(v1 + 1 < version1.size() && version1[v1] == '0') v1++;
        while(v2 + 1 < version2.size() && version2[v2] == '0') v2++;
        if(v1 < version1.size() && version1[v1] == '.') v1--;
        if(v2 < version2.size() && version2[v2] == '.') v2--;
        while(v1 < version1.size()){
            if((v1 < version1.size() && version1[v1] == '.') || (v2 < version2.size() && version2[v2] == '.')){
                v1++;
                v2++;
                while(v1 < version1.size() && version1[v1] == '0') v1++;
                while(v2 < version2.size() && version2[v2] == '0') v2++;
                if(v1 < version1.size() && version1[v1] == '.') v1--;
                if(v2 < version2.size() && version2[v2] == '.') v2--;
            }
            int flag = 0,cur1= v1,cur2 = v2;
            if(cur2 >= version2.size()){
                if(version1[cur1] > '0') return f ? -1 : 1;
                v1++;
            }else{
                while(cur1 < version1.size() && cur2 < version2.size() && version1[cur1] != '.' && version2[cur2] != '.'){
                    if(!flag && version1[cur1] != version2[cur2]) flag = version1[cur1] > version2[cur2] ? 1 : -1;
                    cur1++;
                    cur2++;
                }
                while(cur1 < version1.size() && version1[cur1] != '.') cur1++;
                while(cur2 < version2.size() && version2[cur2] != '.') cur2++;
                if(cur1 - v1 > cur2 - v2) return f ? -1 : 1;
                if(cur1 - v1 < cur2 - v2) return f ? 1 : -1;
                if(flag) return f? -flag : flag;
                v1 = cur1;
                v2 = cur2;
            }
        }
        return 0;
    }
};
```
