```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        vector<string> str(numRows,"");
        string result;
        int m=0,flag=-1;
        for(auto c:s){
            str[m]+=c;
            if(m==0||m==numRows-1) flag=-flag;
            m +=flag;
        }
        for(auto ch:str) result +=ch;
        return result;
    }
};
```
![image.png](https://pic.leetcode-cn.com/3d089274280225f85455d08891e681253352195493ae49cb2b7c823a496756d7-image.png)
