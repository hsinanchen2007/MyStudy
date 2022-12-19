### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {

        if (chars.empty())
        {
            return 0;
        }

        int count = 1; //某个字符的出现次数

        int j = 1; //待填入字符的位置，也是压缩后的字符数组长度
        for (int i = 0; i < chars.size() - 1; ++i)
        {
            if (chars.at(i + 1) != chars.at(i))
            {
                //若字符的出现次数大于1 则将次数写入字符数组
                if (count > 1 && count <= 9)
                {
                    chars.at(j++) = '0' + count;
                }
                else if (count > 9)
                {
                    string s = to_string(count);
                    for (int k = 0; k < s.size(); ++k)
                    {
                        chars.at(j++) = s.at(k);
                    }
                }

                //写入下一个不同的字符
                chars.at(j++) = chars.at(i + 1);

                //重置字符次数
                count = 1;
            }
            else
            {
                ++count;
            }
        }

        //写入最后一个字符的次数
        if (count > 1 && count <= 9)
        {
            chars.at(j++) = '0' + count;
        }
        else if (count > 9)
        {
            string s = to_string(count);
            for (int k = 0; k < s.size(); ++k)
            {
                chars.at(j++) = s.at(k);
            }
        }

        return j;
    }
};
```