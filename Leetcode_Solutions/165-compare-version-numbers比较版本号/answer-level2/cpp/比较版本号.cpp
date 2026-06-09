### 解题思路
两个字符串都没到头的情况下, 碰到 '.' 之后, 将前一段数字字符串进行比较, 如果开头是0就跳过, 根据余下长度或者逐位判断大小
如果有一个到头了, 就遍历另一个剩下的字符, 根据是否有大于0的字符进行判断
68.39% 5.20% 4ms 8.8MB

### 代码

```cpp
class Solution {
public:
    int compare(string version1, string version2, int l1, int r1, int l2, int r2)
    {
        int i1 = l1, i2 = l2;
        while (i1 < r1 && version1[i1] == '0') ++i1;
        while (i2 < r2 && version2[i2] == '0') ++i2;
        if (r1-i1 > r2-i2) return 1;
        else if (r1-i1 < r2-i2) return -1;
        else
        {
            while (i1 < r1)
            {
                if (version1[i1] > version2[i2])
                    return 1;
                else if (version1[i1] < version2[i2])
                    return -1;
                ++i1;
                ++i2;
            }
            return 0;
        }
    }

    int compareVersion(string version1, string version2)
    {
        int idx1 = 0, idx2 = 0;
        int len1 = version1.length(), len2 = version2.length();
        int mark1 = 0, mark2 = 0;
        while (idx1 < len1 || idx2 < len2)
        {
            if (idx1 < len1 && idx2 < len2)
            {
                while (idx1 < len1 && version1[idx1] != '.') ++idx1;
                while (idx2 < len2 && version2[idx2] != '.') ++idx2;
                int temp = compare(version1, version2, mark1, idx1, mark2, idx2);
                if (temp == 1) return 1;
                if (temp == -1) return -1;
                mark1 = idx1+1;
                mark2 = idx2+1;
            }
            else if (idx1 < len1)
            {
                while (idx1 < len1)
                {
                    if (version1[idx1] == '.') ++idx1;
                    if (version1[idx1] - '0' > 0) return 1;
                    ++idx1;
                }
                return 0;
            }
            else if (idx2 < len2)
            {
                while (idx2 < len2)
                {
                    if (version2[idx2] == '.') ++idx2;
                    if (version2[idx2] - '0' > 0) return -1;
                    ++idx2;
                }
                return 0;
            }
            ++idx1;
            ++idx2;
        }
        return 0;
    }
};
```