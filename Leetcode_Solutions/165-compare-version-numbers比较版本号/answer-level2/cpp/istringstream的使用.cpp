题目不难 看到评论里使用istringstream的方法非常优雅，如下👇
```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        char c;
        int v1,v2;
        istringstream its1(version1);
        istringstream its2(version2);
        
        while(bool(its1>>v1) + bool(its2>>v2)){
            if(v1>v2) return 1;
            if(v1<v2) return -1;
            
            v1=0;
            v2=0;
            its1>>c;
            its2>>c;
            
        }
        
        return 0;
    }
};
```
