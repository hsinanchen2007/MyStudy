### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> aaa;
        string bbb;
        int len=path.length();
        if(len==0||(len==1&&path[0]!='/')) return path;
        if(len==1) return "/";
        int flag=1;
        for(int i=1;i<len;i++){
            if(path[i]=='/'&&path[i-1]=='/') continue;
            if(path[i]=='/'){
                    if(bbb=="..") {if(aaa.size()>=1) aaa.pop_back();}
                    else if(bbb==".") {bbb="";continue;}
                    else aaa.push_back(bbb);
                    bbb="";
            }
            else {
                bbb+=path[i];
                if(i==len-1){
                    if(bbb=="..") {if(aaa.size()>=1) aaa.pop_back();}
                    else if(bbb==".") {bbb="";continue;}
                    else aaa.push_back(bbb);
                    bbb="";
                }
            }
        }
        len=aaa.size();bbb="";
        if(len==0) return "/";
        for(int i=0;i<len;i++){
            bbb+='/';
            bbb+=aaa[i];
        }
        return bbb;
    }
};
```