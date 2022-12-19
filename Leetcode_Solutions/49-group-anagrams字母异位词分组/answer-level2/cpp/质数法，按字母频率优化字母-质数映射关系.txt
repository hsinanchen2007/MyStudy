参考题解，这道题最巧妙的方法是质数法，即，将26个英文字母对应于一个质数，如此，对于同字母异位词，它们字母对应质数的乘积便是相等的，否则必然不等。但这里的问题是，乘积可能会溢出。

解决溢出，最简单的方法就是应用uint。实测把int换成uint后，就没有溢出状况了。当然，如果还想进一步缩短用时，可以思考如何尽可能地让单词的乘积值更小。我的思路是：英文字母与质数的对应关系就不应简单地用ascii码对应，而是应当根据英文字母在英语单词中总体的频率来分配，使出现更频繁的字母所对应的质数更小。

根据《密码和隐密写作》，字母按频率排序为：ETAONRISHDLFCMUGYPWBVKJXQZ。为此，通过一个简单的映射：
```
string alphabet_sorted="ETAONRISHDLFCMUGYPWBVKJXQZ";
int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};
int prime_sorted[26];
for(int i=0;i<26;i++){prime_sorted[alphabet_sorted[i]-'A']=prime[i];}
```
映射后，可得到的质数排列为：
```
5,73,43,29,2,41,59,23,17,89,83,31,47,11,7,67,101,13,19,3,53,79,71,97,61,103
```
当然，实测即便是用上这种映射关系，在使用int的情况下依旧会溢出，还是得用uint，但效果是有的，通过多次提交对比，使用这种映射的执行用时会更低。
最后贴出我的代码：
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<uint,vector<string>> mp;
        int prime_sort[26]={5,73,43,29,2,41,59,23,17,89,83,31,47,11,7,67,101,13,19,3,53,79,71,97,61,103};
        //int prime_sort[26]={2,3,5,7,11,13,17,19,23,29,31,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103};
        int i;
        uint key;
        for(i=0;i<strs.size();i++){
            key=1;
            for(char c:strs[i]){
                key*=prime_sort[c-'a'];
            }
            if(mp.count(key)) mp[key].push_back(strs[i]);
            else{
                vector<string> subset;
                subset.push_back(strs[i]);
                mp[key]=subset;
            }
        }
        vector<vector<string>> res;
        unordered_map<uint,vector<string>>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};
```