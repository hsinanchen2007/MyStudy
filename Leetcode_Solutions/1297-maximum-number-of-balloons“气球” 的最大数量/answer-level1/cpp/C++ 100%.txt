```
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> m(5,0);             //数组存储，对应关系：0=b,1=a,2=l,3=o,4=n
        for(int i=0;i<text.size();i++){
            if(text[i]=='b') m[0]++;
            else if(text[i]=='a') m[1]++;
            else if(text[i]=='l') m[2]++;
            else if(text[i]=='o') m[3]++;
            else if(text[i]=='n') m[4]++;
        }
        m[2]/=2;
        m[3]/=2;//l和o出现两次
        sort(m.begin(),m.end());//返回最小的
        return m[0];
    }
};
```
