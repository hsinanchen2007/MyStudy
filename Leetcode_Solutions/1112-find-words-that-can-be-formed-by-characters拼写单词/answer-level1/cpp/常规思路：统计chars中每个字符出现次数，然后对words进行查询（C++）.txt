常规思路：用count[26]统计chars中每个字符出现的次数,
         之后对words中字符串进行查询时，首先拷贝原count数组，通过判断拷贝的数组元素是否为0来          确定是否继续查询下去。
         时间效率：56ms（超95.42%）, 空间效率: 17.9MB（超60.32%）

class Solution {
    int find(string s, const int count[])  //不改变原数组
    {
        int b[26];
        memcpy(b, count, 26 * sizeof(int));  //拷贝一个数组
        for(int i=0;i<s.size();i++)
        {
            if(b[s[i]-'a']==0) return 0;
            else b[s[i]-'a']--;
        }
        return s.size();
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        if(words.size()==0) return 0;
        int count[26] = {0};
        int sum = 0;
        for(int i=0;i<chars.size();i++) count[chars[i]-'a']++;
        for(int i=0;i<words.size();i++) sum += find(words[i],count);
        return sum;
    }
};