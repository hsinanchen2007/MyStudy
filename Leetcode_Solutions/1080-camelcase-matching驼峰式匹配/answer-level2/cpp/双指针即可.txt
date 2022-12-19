1. 针对每个query， 双指针指向query和pattern的头部。
2. 遍历query。
3. 对于query中的大写字母，如果pattern指针已经到底或者两者不相等，说明不能匹配，退出遍历；否则pattern指针+1。
4. 对于query中的小写字母，如果pattern指针没到底且两者相等，部分匹配成功，pattern指针+1。
5. 判断是否匹配的条件就是两个指针是否都到达字符串末尾。
```
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size(), false);

        for(int i = 0; i < queries.size(); i++) {
            int j = 0, k = 0;
            while(j < queries[i].size()) {
                if(queries[i][j] >= 'A' && queries[i][j] <= 'Z') {
                    if(k >= pattern.size() || queries[i][j] != pattern[k]) break;
                    k++;
                }
                else {
                    if(k < pattern.size() && queries[i][j] == pattern[k]) k++;
                }
                j++;
            }
            res[i] = j >= queries[i].size() && k >= pattern.size();
        }

        return res;
    }
};
```
