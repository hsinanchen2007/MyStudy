### 解题思路
转：
暴力
c++不如java方便

### 代码

```cpp
class Solution {
public:
     vector<string> restoreIpAddresses(string s) {
        vector<string> v;
        int a,b,c,d;
        string s1,s2,s3,s4,ss;
        int n1,n2,n3,n4;
        for(a=1;a<4;a++)
           for(b=1;b<4;b++)
              for(c=1;c<4;c++)
                    for(d=1;d<4;d++){
                       if(a+b+c+d==s.size()){
                          s1=s.substr(0,a);n1=stoi(s1);
                          s2=s.substr(a,b);n2=stoi(s2);
                          s3=s.substr(a+b,c);n3=stoi(s3);
                          s4=s.substr(a+b+c,d);n4=stoi(s4);
                          if(n1<=255&&n2<=255&&n3<=255&&n4<=255){
                              ss=to_string(n1)+"."+to_string(n2)+"."+to_string(n3)+"."+to_string(n4);
                              if(ss.size()==s.size()+3) v.emplace_back(ss);
                          }
                       } 
                   } 
        return v;            
    }
};
```