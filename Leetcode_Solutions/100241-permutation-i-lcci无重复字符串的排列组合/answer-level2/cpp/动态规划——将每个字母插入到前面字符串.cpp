将每个字母插入到前面字符串所有可能的情况：
例如："qwe"
第一轮：q
第二轮：将w插入q,有两种情况：wq, qw
第三轮：将e插入wq, qw中去 即：ewq,weq,wqe;eqw,qew,qwe六种情况
```
class Solution {
public:
    vector<string> permutation(string S) {
        int len = S.length();
        vector<string> res,result;
        if(len <=0 )
            return res;
        string tmp = S.substr(0,1);
        res.push_back(tmp);
        for(int i=1;i<len;i++){
            int count = res.size();
            for(int j=0;j<count;j++){
                string origin = res[j];
                int length = origin.length();
                for(int k=0;k<length;k++){
                    string t=origin.substr(0,k)+S[i]+origin.substr(k);
                    res.push_back(t);
                }
                res.push_back(origin+S[i]);
            }
            res.erase(res.begin(),res.begin()+count);
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/4db8417cee5f0148a47bfbc5a69bdf9949a0c6e53b5dc9695a727dd12c77a47d-image.png)
