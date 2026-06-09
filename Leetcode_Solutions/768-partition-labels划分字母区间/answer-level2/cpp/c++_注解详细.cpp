```cpp
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int M[26] = {0};
        int n = S.size();

        //记录S中每个字母最右边的索引
        for (int i=0; i<n; i++)
            M[S[i]-'a'] = i;

        //start表示每段开始的位置
        int i = 0, j = 0, start = 0;
        while (start<n){
            j = M[S[start]-'a'];//j表示S[start]最右边的索引
            //更新j的值，最后j为每段第一个字母和该字母最大索引之间所有字母索引的最大值
            while (i<j){
                if (M[S[i]-'a']>j) 
                    j = M[S[i]-'a'];
                i++;
            }
            res.emplace_back(j-start+1);
            //更新start
            start = j+1;
        }
        return res;
    }
};
```