``
```
```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int pos1 = 0;
        int pos2 = 0;
        string s1;
        string s2;
        int result = 0;
        while(pos1<len1&&pos2<len2){
            while(version1[pos1]!='.'&&pos1<len1){
                s1+=version1[pos1];
                pos1++;
            }
            while(version2[pos2]!='.'&&pos2<len2){
                s2+=version2[pos2];
                pos2++;
            }
            pos1++;
            pos2++;
            if(stoi(s1)>stoi(s2)){result = 1;break;}
            if(stoi(s1)<stoi(s2)){result = -1;break;}
            s1 = "";
            s2 = "";
        }
        if(result == 0){
            while(pos1<len1){
               if(version1[pos1] != '0' && version1[pos1] != '.'){result = 1;break;}
                pos1++;
            }
            while(pos2<len2){
                if(version2[pos2] != '0' && version2[pos2] != '.'){result = -1;break;}
                pos2++;
            }
        }
        return result;
    }
};
```
