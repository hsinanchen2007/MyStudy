```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1=0,start2=0;
        while(start1<version1.size()||start2<version2.size()){
            int end1=start1;
            while(end1<version1.size()&&version1[end1]!='.')++end1;
            int end2=start2;
            while(end2<version2.size()&&version2[end2]!='.')++end2;
            int res=compare(start1>version1.size()?"":version1.substr(start1,end1-start1),start2>version2.size()?"":version2.substr(start2,end2-start2));
            if(res!=0)return res;
            start1=end1+1;
            start2=end2+1;
        }
        return 0;
    }
    int compare(string v1,string v2){
        int i1=0;
        if(!v1.empty())i1=std::stoi(v1);
        int i2=0;
        if(!v2.empty())i2=std::stoi(v2);
        if(i1>i2)return 1;
        else if(i1<i2)return -1;
        return 0;
    }
};
```
