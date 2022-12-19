### 解题思路
 计数比较法，统计licensePlate 中每个字母出现的次数，
统计 words 中 每个单词的字母出现次数，
当 words 中 单词 word 的字母出现次数大于等于licensePlate 中每个字母出现的次数，且该 word具有最小长度时，
该 word为最短完整词，

### 代码

```cpp
class Solution {
public:
    //计数比较法，统计licensePlate 中每个字母出现的次数
    //统计 words 中 每个单词的字母出现次数
    // 当 words 中 单词 word 的字母出现次数大于等于licensePlate 中每个字母出现的次数，且该 word具有最小长度时
    //该 word为最短完整词
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string ans = "";
        lowwerCase(licensePlate);
        vector<int> target = count(licensePlate);
     
        for(auto word : words)
        {
            //word 为完整词
            if(isCompleteWord(target, count(word)))
            {
               if(ans.size() == 0 || word.size() < ans.size())
                    ans = word;
            }
        }
        return ans;
    }

    //统计 s 中每个字母出现的次数
    vector<int> count(string s)
    {
        vector<int> a(26, 0);
        for(auto c : s)
        {
            if(c >= 'a' && c <= 'z')
            {
                a[c-'a']++; 
            }
        }
        return a;
    }

    //根据 count 判断是否为完整词
    // count1为 licensePlate 的， count2 属于 word
    bool isCompleteWord(vector<int>  count1, vector<int>  count2)
    {
        for(int i = 0; i < 26; i++)
        {
            //licensePlate中某个单词出现次数大于 word
            if(count1[i] > count2[i])
                return false;
        }
        return true;
    }

    //大写字母转为小写
    void lowwerCase(string & s)
    {
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
    }
    
};
```