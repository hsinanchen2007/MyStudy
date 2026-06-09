写一个循环，遍历所有得长度为len 得字串， 满足不同字母数 <= maxLetters 的用map统计次数，最终比较map中的最大值 就是答案

len 的长度是 大于等于minSize 小于等于maxSize

分析一下，如果当前遍历的子串长度len_now >  上一次遍历的长度 len_before 那 len_now 得最大值一定 小于等于len_before 因为len_now 得子串一定包含len_before得子串

所以需要遍历得长度只有一个 minSize， maxSize 是没有任何用得
```
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int res = 0;
        set<string> sons;
        map<string, int> hash;
        for(int len = minSize; len <= minSize; len ++){
            for(int i = 0; i < s.size() - len + 1; i ++){
                string son = s.substr(i, len);
                if(getLetters(son) <= maxLetters){
                    hash[son] ++;
                }
            }
        }
        auto it = hash.begin();
        while(it != hash.end()){
            res = max(res, it->second);
            it ++;
        }
        return res;
    }
    int getLetters(string son){
        int cnt = 0;
        set<char> hash;
        for(auto s:son){
           hash.insert(s);
        }
        return hash.size();
    }
};
```
