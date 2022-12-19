```
class Solution {
public:
    int fun1(string &v){
        int sum=0;
        for(int i=0;i<v.size();i++)
            sum+=v[i]-'0'+sum*10;
        return sum;
    }
    void fun(string &v,vector<int>&temp){
            int t=0;
        for(int i=0;i<v.size();i++){
             if(v[i]=='.'){
                 string s=v.substr(t,i-t);                
                     temp.push_back(fun1(s));
                    t=i+1;
             }else if(i==v.size()-1){
                 string s=v.substr(t,i-t+1);               
                     temp.push_back(fun1(s));
             }
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int>v1,v2;
        fun(version1,v1);
        fun(version2,v2);
        int n1=v1.size();
        int n2=v2.size();
        int size=max(n1,n2);
        if(n1<n2){
            for(int i=0;i<n2-n1;i++){
                v1.push_back(0);
            }
        }
        else if(n1>n2){
            for(int i=0;i<n1-n2;i++)
                v2.push_back(0);
        }
        for(int i=0;i<size;i++){
            if(v1[i]>v2[i])
                return 1 ;
            else if(v1[i]<v2[i])
                return -1;
        }
        
        return 0;
        }
};
```
