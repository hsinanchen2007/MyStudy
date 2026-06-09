### 解题思路
此处撰写解题思路:思路见代码
执行用时 :4 ms, 在所有 C++ 提交中击败了93.52%的用户
内存消耗 :6.9 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp;     /*返回的最长公共子串*/
        if(strs.empty()) return lcp;
        stable_sort(strs.begin(),strs.end(),[](const string &a,const string &b)
        {return a.size()<b.size();});       /*按字串大小排序，相等的按字典序排*/
        auto beg=strs.begin();
        string firstword=*beg;     /*记录容器中第一个字符串*/
        beg++;                     /*转到下一位元素*/
        int n=firstword.size();
        int cnt=0;      /*记录相同前缀位数*/
        for(int i=0;i<n;++i){
            int flag=1; /*记录相同前缀的元素个数*/
            auto iter=beg;  /*遍历起始位置*/
            while(iter!=strs.end()){
                if(firstword[i]==(*iter)[i]){
                    ++flag; /*若相等，flag+1*/
                    ++iter;
                }   
                else 
                    break;  /*不相等直接跳出循环*/
            }
            if(flag==strs.size())
                ++cnt;      /*若flag=数组元素个数，则公共前缀个数加1*/
            else
                break;      /*若不相等，跳出最外层循环*/
        }       
        lcp=firstword.substr(0,cnt);
        return lcp;       
    }
};
```