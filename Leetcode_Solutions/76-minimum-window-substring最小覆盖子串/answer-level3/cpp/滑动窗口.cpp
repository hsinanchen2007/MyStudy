```
//代码有点low，思路其实很简单
//左右指针初始为0，右指针先从左边向右找,装满所有t中字母后,左指针向右移动直到装不下t中所有字母,右指针继续向右找(循环往复)
class Solution {
public:
    int i,j,res,site,dist,len;
    char rec;
    bool flag;
    unordered_map<char,int> mp,tmp;
    string minWindow(string s, string t) {
        res = INT_MAX;len = s.length();
        for(auto&it:t) mp[it]++;
        for(i=j=0;j<len;j++) {
            tmp[s[j]]++;
            flag = true;
            while(j<len&&flag) {//找到能装满所有t中字母的右指针位置
                for(auto&elem:mp) if(tmp[elem.first]<elem.second) {flag=false;rec=elem.first;break;}
                if(flag) break;
                else flag = true;
                for(j++;j<len&&s[j]!=rec;j++) tmp[s[j]]++;
                if(j==len) break;
                else tmp[s[j]]++;
            }
            if(j==len) break;
            dist = j - i + 1;
            if(res>dist) res = dist,site = i;
            while(i<j) {//左指针右移
                if(mp.count(s[i])) {
                    tmp[s[i]]--;
                    if(tmp[s[i]]<mp[s[i]]) {i++;break;}
                    else i++,dist--;
                }else i++,dist--;
                if(res>dist) res = dist,site = i;
            }
        }
        return res==INT_MAX?"":string(s.begin()+site,s.begin()+site+res);
    }
};
```
