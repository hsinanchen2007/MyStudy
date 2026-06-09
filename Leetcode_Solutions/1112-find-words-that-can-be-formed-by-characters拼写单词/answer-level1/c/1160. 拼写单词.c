### 解题思路
这道题其实非常的简单，就是问包含问题
现在有
words = ["cat","bt","hat","tree"]
chars = "atach"
问长度之和
其实就是问words里的每一个单词有没有被chars包含
现在chars
a = 2 ， t = 1 ，c = 1， h = 1
所以cat 包含， bt不包含，因为chars里没有b，hat也包含，tree不包含因为没有r，没有e
所有长度之和就是cat + hat = 6

那么问题就变成了统计chars里有什么，然后遍历整个words去对应检测就好啦。
```
for(int k = 0 ; k < 26; k++)
    temp[k] = zm[k];
```
这一步的目的只是让temp数组恢复到原来的正常值而已

 
### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        char zm[26];
        for(int i = 0; i < 26; i++)
            zm[i] = 0;

        for(int i = 0; i < chars.length(); i++)
            zm[chars[i] - 'a']++;
        int max = 0;

        for(int i = 0 ; i < words.size(); i++)
        {
            char temp[26];
            int j = 0;
            int len =  words[i].length();
            for(int k = 0 ; k < 26; k++)
                temp[k] = zm[k];

            for(j = 0; j < len; j++)
                if(temp[words[i][j] - 'a'] > 0)
                    temp[words[i][j] - 'a']--;
                else
                    break;

            if(j == len)
                max += len;
        }

        return max;
    }
};
```