### 解题思路
思路：这个问题最主要的就是求后缀重复的个数
1、先逆序
2、再升序排列
3、为了在后面for循环中不漏掉最后一个字符串，特意在排序后加了一个空字符串
4、后面计算#个数的时候要减去1

### 代码

```cpp

/**
思路：这个问题最主要的就是求后缀重复的个数
1、先逆序
2、再升序排列
3、为了在后面for循环中不漏掉最后一个字符串，特意在排序后加了一个空字符串
4、后面计算#个数的时候要减去1
**/

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        if (words.size() == 0) return 0;
        if (words.size() == 1) return words[0].length() + 1;

        std::vector< std::string > copy;
        for (int i = 0; i < words.size(); ++i)
        {
            // 对每个字符串逆序
            copy.push_back(std::string(words[i].rbegin(), words[i].rend()));
        }
        // 对逆序后的排序
        std::sort(copy.begin(), copy.end());
        // 为了不在后面循环的时候漏掉最后一个字符串，添加一个无用的字符串
        copy.push_back("");

        // 依次检查，前一个是否为后面的前缀
        // 前缀重复的个数
        int cnt = 0;
        // 字符个数
        int characters = 0;
        for (int i = 0; i < copy.size() - 1; ++i)
        {
            // 前一个是后一个的前缀
            if (copy[i + 1].find(copy[i]) == 0)
            {
                ++cnt;                
            }
            else
            {
                characters += copy[i].length();
            }
        }

        // (#个数， 前面加另一个空字符串，所以-1)， 加上字符个数
        return (copy.size() - cnt - 1) + characters;
    }
};
```