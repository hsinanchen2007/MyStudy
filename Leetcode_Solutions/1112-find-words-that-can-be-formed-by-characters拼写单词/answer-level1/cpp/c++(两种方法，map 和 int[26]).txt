### 方法一：哈希表
- 思路：
  - 构造字母表哈希表，key为每个字符，value为key出现的次数
  - 对每个单词同样构造哈希表
  - 如果单词中的key都在字母表中出现，且次数不大于字母表中，则在结果上加上该串的长度
- 时间复杂度：
  - o(n),至少遍历所有字符串一遍
- 空间复杂度：
  - o(S),S为字符集大小
- 结果:
  - 用时：8%（304ms）
  - 内存：5%（57.4MB）
```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        unordered_map<char,int> char_map;
        for(char chr:chars) char_map[chr]++; // 两行达到python Counter的效果
        for(string word:words){
            bool match=true;
            unordered_map<char,int> word_map;
            for(char chr:word) word_map[chr]++; // 两行达到python Counter的效果
            for(char chr:word){
                if(char_map[chr]<word_map[chr]){
                    match=false;
                    break;
                }
            }
            if(match) res+=word.size();
        }
        return res;
    }
};
```

### 方法二：用int[26]代替map来优化空间和时间
- 思路：
  - 本题知道字符集的大小（26），可以用定长数组代替map
- 时间复杂度：
  - o(n),至少遍历所有字符串一遍
- 空间复杂度：
  - o(S),S为字符集大小
- 结果:
  - 用时：73%（68ms）
  - 内存：60%（18.1MB）
```
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        int char_map[26]={0};
        for(char chr:chars) char_map[chr-'a']++; // 用int[26]代替map，注意索引为 chr-'a'
        for(string word:words){
            bool match=true;
            int word_map[26]={0};
            for(char chr:word) word_map[chr-'a']++; // 用int[26]代替map，注意索引为 chr-'a'
            for(char chr:word){
                if(char_map[chr-'a']<word_map[chr-'a']){
                    match=false;
                    break;
                }
            }
            if(match) res+=word.size();
        }
        return res;
    }
};
```
> -------------------------------------------------
> > \>\>\>[**我的算法题本 - 算法菜鸟之路**](https://github.com/lorwin0130/Algorithm-newbie)
> 会记录做过题的**不同解法、思路、套路总结以及个人思考**
> 欢迎各位大佬**来讨论呀**，欢迎**star (U^_^U)** 
> -------------------------------------------------