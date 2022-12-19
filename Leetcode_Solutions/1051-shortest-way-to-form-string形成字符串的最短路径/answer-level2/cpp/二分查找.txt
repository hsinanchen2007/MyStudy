首先将source字符串的每个字符对应的位置存在数组S里，例如source为abcabc时，那么a字符位置是0和3，b是1、4，c是2、5，然后查找target从开始到结尾字符所在对应数组中的最小位置，例如target为baab,那么首先看到b字符在数组S['b'-'a']的位置是1，然后由于之后查询的字符位置肯定大于1，所以使用upper_bound进行二分查找，查询下个字符a的位置是3（>1的位置)，由于下个a字符没有3之后的，所以从头开始，查询到的位置是0，最后查询b的位置1，结束。
```
class Solution {
public:
    int shortestWay(string source, string target) {
        if(target.size()==0) return 0;
        vector<vector<int>> v(26);
        for(int i=0;i<source.size();i++){
            v[source[i]-'a'].push_back(i);
        }
        int cnt = 1;
        int pos = -1;
        for(int i = 0;i<target.size();i++){
            if(v[target[i]-'a'].size()==0){
                return -1;
            }
            auto it = upper_bound(v[target[i]-'a'].begin(), v[target[i]-'a'].end(), pos);
            if(it==v[target[i]-'a'].end()){
                cnt++;
                i--;
                pos = -1;
            }else{
                pos = *it;
            }
        }
        return cnt;
    }
};
```