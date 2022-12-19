开辟26的数组用来存字母出现的次数，此时有两个选择，存第一个会比较好(因为会有第一个很短，第二个很长的情况)。
```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size()>magazine.size())  //直接返回
            return false;
        if(ransomNote.size()==0)//直接返回
            return true;
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));//初始化为0
        int noteSize = ransomNote.size();
        for(auto s:ransomNote)
        {
            cnt[s-'a']++;
        }
        for(auto s:magazine)
        {
            if(cnt[s-'a']>0)
            {
                cnt[s-'a']--;
                noteSize--;
                if(noteSize == 0) //为0代表全部都找到，直接返回答案
                    return true;
            }
        }
        return false;
    }
};
```
