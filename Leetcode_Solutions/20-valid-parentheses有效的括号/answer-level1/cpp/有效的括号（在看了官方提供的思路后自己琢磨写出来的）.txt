    第一次写题解没搞清楚代码格式怎么设置...这是删了第一次提交之后重新发布的QAQ
    如题，本编程菜鸡刚看到题目的时候一脸懵逼。后来看到官方提供的几个思路小视频才琢磨出来这个。
    执行用时0ms，内存消耗6.3MB。
```
class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)
            return true;
        if(s.length()%2!=0)
            return false;
        vector<char> sVector; 
        int eraseNum=0;
        int vectorSize=-1;
        for(int i=0;i<s.length();i++)
        {
            sVector.push_back(s[i]);
            vectorSize++;
            if(vectorSize>=1)
            {
                if((sVector[vectorSize]==')'&&sVector[vectorSize-1]=='(')||(sVector[vectorSize]==']'&&sVector[vectorSize-1]=='[')||(sVector[vectorSize]=='}'&&sVector[vectorSize-1]=='{'))
                {
                    sVector.pop_back();sVector.pop_back();
                    vectorSize-=2;
                }
            }
            else
                continue;
            
        }
        if(vectorSize!=-1)
            return false;
        else
            return true;
    }
};
```
