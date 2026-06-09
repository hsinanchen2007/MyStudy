
思路：
将每个version两个$.$之间的字符分割出来，然后用一个vector存储分割出来的字符的起始位置和长度（pair->first：起始位置，pair->second：长度），分别比较两个vector即可。
代码：
```
class Solution {
public:
    void split(string str,vector<pair<int,int>>& pos){
        int s=0,t=0,n=str.size();
        while(s<n){
            while(s<n&&str.at(s)=='0') s++;
            t=s;
            while(t<n&&str.at(t)!='.') t++;
            pos.push_back(pair{s,t-s});
            s=t+1;
        }
    }
    int compare(string s1,int n1,string s2,int n2){
        if(n1!=n2) return n1-n2;
        for(int i=0;i<n1;++i){
            if(s1.at(i)!=s2.at(i))  return s1.at(i)-s2.at(i);
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        vector<pair<int,int>> pos1,pos2;
        split(version1,pos1);
        split(version2,pos2);
        int n1=pos1.size(),n2=pos2.size();
        int i=0,j=0;
        while(i<n1&&j<n2){
            int s1=pos1[i].first,l1=pos1[i].second;
            int s2=pos2[j].first,l2=pos2[j].second;
            int cmp=compare(version1.substr(s1,l1),l1,version2.substr(s2,l2),l2);
            if(cmp<0) return -1;
            else if(cmp>0) return 1;
            ++i,++j;
        }
        if(j<n2){
            while(j<n2&&pos2[j].second==0) j++;
            if(j<n2) return -1;
        }
        else if(i<n1){
            while(i<n1&&pos1[i].second==0) i++;
            if(i<n1) return 1;
        }
        return 0;
    }
};
```