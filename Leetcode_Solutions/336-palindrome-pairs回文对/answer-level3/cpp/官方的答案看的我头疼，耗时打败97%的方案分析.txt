# 1 暴力思路分析
很多人上来就看最佳答案，这不是一个好习惯，暴力方案大都数人都能想出来，想出来后再跟最佳方案做对比分析，才是真的有意思。
这道题的暴力解非常简单，两层for循环，把字符串拼接一起判断是不是回文即可。
代码如下
```
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (is_palindrome(words[i] + words[j])) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
    bool is_palindrome(string s) {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
```
耗时，n为字符串数量，k是最长字符串长度。
两层for循环，n^2，然后判断字符串是不是回文，耗时k。n^2*k即为最终耗时。

# 2 优化方案
我们有没有一种方案，能够让一个字符串，快速的寻找和判断是不是目标字符串呢？
答案是有的，切入点就是，什么情况下，两个字符串组合起来会是回文。
三种情况。
第一，"abc" "cba"，这两个字符串组合起来必然是回文。
第二，"abc(xxxx)" "cba"，这种情况下，只要xxxx为回文，那么组合起来也肯定是回文。
第三，"(xxxx)abc"，"cba" ，这种请你看下，只要xxxx为回文，那么组合起来肯定也是回文。

所以，接下来的工作，就是如何根据这三种情况，进行各种加速和剪枝的工作。
先把所有字符串hash起来，再把长度存入一个set里面。

第一种情况
字符串反转，查表寻找是否有满足字符串

第二种情况
字符串反转，"abc(xxxx)"反转为"(xxxx)cba"。
遍历长度set，截取的（xxxx）也就是字符串的长度。
我们先判断(xxxx)是不是回文，然后再hash查表cba是不是存在。

第三种情况
字符串反转，"(xxxx)abc"反转为"cba(xxxx)"
遍历长度set，截取的（xxxx）也就是字符串的长度
那么我们先判断(xxxx)是不是回文，再hash查表cba是否存在即可。

字符串数量为n，字符串长度数组为m，最长字符串长度为k，最短为j
那么耗时就是n*m*(k-j)/2
可以看到整体耗时就少了很多了

代码如下，这个代码是抄的别人的，代码风格不是很好，但耗时和内存优化的确是很给力。
```
class Solution {
public:
    bool f(string& s,int left,int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        string test = "abcdef";
        cout << test.substr(3) << endl;
        unordered_map<string,int> words_index_map;
        set<int> word_size_set;
        int n = words.size();
        for(int i=0;i<n;i++){
            words_index_map[words[i]]=i;
            word_size_set.insert(words[i].size());
        }
        vector<vector<int>> res;
        for(int i=0; i < words.size(); i++){
            string word_reverse = words[i];
            reverse(word_reverse.begin(), word_reverse.end());
            //如果reverse的字符在map中存在，那么相加肯定是个
            if(words_index_map.count(word_reverse) && words_index_map[word_reverse] != i){
                res.push_back({words_index_map[word_reverse], i});
            }
            int length = word_reverse.size();

            for(auto it = word_size_set.begin(); *it != length; it++){
                int d = *it;
                if(f(word_reverse, 0, length - d - 1) && 
                    words_index_map.count(word_reverse.substr(length - d))){
                    res.push_back({i, words_index_map[word_reverse.substr(length - d)]});
                }
                if(f(word_reverse, d, length - 1) && 
                    words_index_map.count(word_reverse.substr(0, d))){
                    res.push_back({words_index_map[word_reverse.substr(0, d)], i});
                }
            }
            
        }
        return res;
    }
};
```
