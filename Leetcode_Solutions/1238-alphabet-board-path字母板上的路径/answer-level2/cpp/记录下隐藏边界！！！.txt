### 解题思路
对于z这个字母这一行隐藏了一个大坑，往下往左时，注意先往左再往下才能够避免踩坑！！！

### 代码

```cpp
class Solution {
public:
    string alphabetBoardPath(string target) {
        //1、使用vector与pair与map进行混搭，每次都以当前坐标更新map中的vecotr
        //此题有大坑，对于题目中隐含的边界条件一定要好好把握，别跳到坑中！！！
        // map<char,vector<pair<int,int>>> mp;
        // int m=target.size();
        // vector<pair<int,int>> tp;
        map<char,pair<int,int>> mp={{'a',make_pair(0,0)},{'b',make_pair(0,1)},{'c',make_pair(0,2)},{'d',make_pair(0,3)},{'e',make_pair(0,4)},{'f',make_pair(1,0)},{'g',make_pair(1,1)},{'h',make_pair(1,2)},{'i',make_pair(1,3)},{'j',make_pair(1,4)},{'k',make_pair(2,0)},{'l',make_pair(2,1)},{'m',make_pair(2,2)},{'n',make_pair(2,3)},{'o',make_pair(2,4)},{'p',make_pair(3,0)},{'q',make_pair(3,1)},{'w',make_pair(4,2)},{'x',make_pair(4,3)},{'y',make_pair(4,4)},{'z',make_pair(5,0)},{'r',make_pair(3,2)},{'s',make_pair(3,3)},{'t',make_pair(3,4)},{'u',make_pair(4,0)},{'v',make_pair(4,1)}};
        int m=0;
        int tx=0,ty=0;string res="";
        while(m<target.size())
        {
            pair<int,int> tp=mp[target[m]];
            int tpx=tp.first;int tpy=tp.second;
            if(tpx>=tx&&tpy>=ty)
            {
                for(int i=tx;i<tpx;++i)
                    res+="D";
                for(int i=ty;i<tpy;++i)
                    res+="R";
            }
            else if(tpx>=tx&&tpy<=ty)
            {
                for(int i=tpy;i<ty;++i)
                    res+="L";
                for(int i=tx;i<tpx;++i)
                    res+="D";
            }
            else if(tpx<=tx&&tpy<=ty)
            {
                for(int i=tpx;i<tx;++i)
                    res+="U";
                for(int i=tpy;i<ty;++i)
                    res+="L";
            }
            else if(tpx<=tx&&tpy>=ty)
            {
                for(int i=tpx;i<tx;++i)
                    res+="U";
                for(int i=ty;i<tpy;++i)
                    res+="R";
            }
            tx=tpx;ty=tpy;res+='!';m++;
        }
        return res;
    }
};
```