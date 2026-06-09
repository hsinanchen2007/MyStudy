### 解题思路
多次提交，取用时和内存的平均值：
用时[7ms],内存[8.8MB]
思路：
先优先排除掉特殊情况,strs的string为空的情况；
string数大于2的时候，以第一个string为标准，剩余的依次和它比较，获得每一个的共同字串数，push到vector<int>存起来；
找到存放各个string和first的公共字串vector的最小值，即为所有字串的最大公共字串数；
【思路二拓展】：其实一开始是想把字符串全部转成ASCII值，然后组成vector<int>,再依次进行 异或 运算，相同数字的异或结果是0，虽然可行，但是复杂度好像是上去了
### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t nSize = strs.size();
        if(nSize<2)//考虑到strs里空string和只有一个string
        {
            return 0==nSize?"":strs[0];
        }
        string strFirst = strs[0];//取第一个string为标杆进行比较
        size_t  szFirst = strFirst.size();
        string strTmp = "";
        int nEachCommon = 0;
        vector <int> vAllCommonCnt ;//申明一个vector<int>,存放第一个string和其他string的共同字符数
        for(size_t ii = 1 ;ii<nSize;ii++)
        {
            nEachCommon = 1;
            strTmp = strs[ii];//一次取值，送入while循环
            if(""==strTmp)
            {
                return "";
            }
            while(0== strTmp.compare(0,nEachCommon,strFirst,0,nEachCommon)&& nEachCommon<=szFirst)//单独比较first字符串和其他字符串的共同字串;并且要加入长度限制,compare函数不检查下标
            {
                nEachCommon++;
            }
            vAllCommonCnt.push_back(nEachCommon-1);//减1是考虑到最后return的string下标是从0开始
        }
        int nMinCommon = *min_element(vAllCommonCnt.begin(),vAllCommonCnt.end());
        return strFirst.substr(0,nMinCommon);
    }
};
```