![image.png](https://pic.leetcode-cn.com/2bdb004dc2add0785097a760b106466df5f1ffa306d72ab8ee028420278ade9a-image.png)
```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res=0,n=words.size();
        vector<pair<int,int>>v(n);//first记录26个字母是否出现，second记录字符串长度
        for(int q=0;q<n;q++){
            int w=0,lenq=words[q].size();
            for(int i=0;i<lenq;i++){
                int a = words[q][i]-'a';
                w|=1<<a;
            }
            v[q]=make_pair(w,lenq);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!(v[i].first & v[j].first)){//如果两个字符串没有重复位 比如1100 & 0011=0
                    res = max(res,v[i].second * v[j].second);
                }
            }
        }
        return res;
    }
};
```