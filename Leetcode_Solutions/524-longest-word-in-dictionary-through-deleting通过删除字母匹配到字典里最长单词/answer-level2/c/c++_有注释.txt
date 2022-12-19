```
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len1 = s.size();
        int len2 = d.size();
        int max = 0;
        int maxIndex = -1;//符合要求的最长字符串索引

        for (int i = 0; i < len2; i++){
            int k = 0;
            for (int j = 0; j < len1; j++){
                if (d[i][k] == s[j]){
                    k++;
                }
                if (k == len1){
                    break;
                }
            }
            int len3 = d[i].size();
            //k等于len3,说明符合要求
            if (k == len3 && len3 >= max){
                //相同长度需要符合字典排序要求
                if (len3 == max && d[i] > d[maxIndex]){
                    continue;
                }
                maxIndex = i;
                max = len3;
            }
        }
        return maxIndex == -1 ? "" : d[maxIndex];
    }
};
```
