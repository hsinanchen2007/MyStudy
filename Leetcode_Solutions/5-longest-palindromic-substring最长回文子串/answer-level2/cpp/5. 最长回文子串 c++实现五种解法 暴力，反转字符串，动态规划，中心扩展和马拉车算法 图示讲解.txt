![5.mp4](daa0cca3-0116-4cf5-817f-68f326689972)

<![1.jpg](https://pic.leetcode-cn.com/ff16ef150fe249917bd42bcc045d1729bdab7ae6cfb399032f5a49eb8c614cb8-1.jpg),![2.jpg](https://pic.leetcode-cn.com/5b85ced28768db07fa1af00b7d6f73fe1d66e7498815c86bdc211b6cd7f41ced-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c2e90861077c490c79f9a8c031b9e68f33dd6169f82b2c09fcabdb06d7213306-3.jpg),![1.jpg](https://pic.leetcode-cn.com/97cdcf2348c2771c45309c35b3fc0e0cef595d5158cf3fa80b4745de5c6c85ef-1.jpg)>

```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string result("");
        int sSize = int(s.size());
        for (int i = 0; i < sSize; i++)
        {
            int maxLength = sSize - i;
            for (int tmpSize = 1; tmpSize <= maxLength; tmpSize++)
            {
                string tmpStr = s.substr(i, tmpSize);
                if (isPalindrome(tmpStr) && tmpStr.size() > result.size())
                {
                    result = tmpStr;
                }
            }
        }
        return result;
    }

    bool isPalindrome(string s)
    {
        int left = 0;
        int right = int(s.size()) - 1;
        for (; left < right; left++, right--)
        {
            if (s[left] != s[right])
            {
                return false;
            }
        }
        return true;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/585f3b862b1f6a1df05e670ac732d7eeb46e5e3bce5d6092e3bc08f145d63f50-1.jpg),![2.jpg](https://pic.leetcode-cn.com/96207ae52edd36041c292de9ea0d28baabf83d9f1c6dd64d124b342ac8d3f502-2.jpg),![3.jpg](https://pic.leetcode-cn.com/a53b0b8fc6dbcee49955d5c0dc5a104a66e38b1988782427fddf1bb34b0ad1a7-3.jpg),![1.jpg](https://pic.leetcode-cn.com/496fa33119ab65dd09f3457428f77431535bf2a0afe816ed1261d4be65bbbbfc-1.jpg),![2.jpg](https://pic.leetcode-cn.com/f1d699687a3909a53cf158b4622be8cd62786d6aed904001d0a9020010fdb7e5-2.jpg),![3.jpg](https://pic.leetcode-cn.com/3a6ca38859b87ef8cb0e35ae8049795455dcfa6cdf5b7ce7f11db0c40d9342eb-3.jpg),![4.jpg](https://pic.leetcode-cn.com/3e6313f364b8f105bc13ea9e50ea4d166880c4c153e61208427c2b0e69e0cc83-4.jpg),![5.jpg](https://pic.leetcode-cn.com/1c5c564dcf96a9c790e167fb992cd7935370babd86e87500667cc05c1806705b-5.jpg),![6.jpg](https://pic.leetcode-cn.com/83d0c05846f89f7f1f8f66b29ece912352c83984bc1b3e280faaa9a378f0bb9e-6.jpg),![7.jpg](https://pic.leetcode-cn.com/9236a1fe1ffec996df0cc5cc0ab7e10646dc31fce499da5a668851fe05e90510-7.jpg)>

```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //判断空字符串的情况
        if (s == "")
        {
            return "";
        }
        string result("");
        int sSize = int(s.size());
        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        vector<int> tmpVec(sSize, 0);
        vector<vector<int>> store(sSize, tmpVec);
        int maxLength = 0, end = 0;

        for (int i = 0; i < sSize; i++)
        {
            for (int j = 0; j < sSize; j++)
            {
                if (s[i] == reverseS[j])
                {
                    //动态规划
                    if (i == 0 || j == 0)
                    {
                        store[i][j] = 1;
                    }
                    else
                    {
                        store[i][j] = store[i - 1][j - 1] + 1;
                    }
                }
                if (store[i][j] > maxLength)
                {
                    //判断比较的字符串是不是来源自同一个字符串
                    int preJ = sSize - 1 - j;
                    int nowJ = preJ + store[i][j] - 1;
                    if (nowJ == i)
                    {
                        end = i;
                        maxLength = store[i][j];
                    }
                }
            }
        }

        result = s.substr(end + 1 - maxLength, maxLength);
        return result;
    }
};
```
```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //判断空字符串的情况
        if (s == "")
        {
            return "";
        }
        string result("");
        int sSize = int(s.size());
        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        vector<int> store(sSize, 0);
        int maxLength = 0, end = 0;

        for (int i = 0; i < sSize; i++)
        {
            for (int j = sSize - 1; j >= 0; j--)
            {
                if (s[i] == reverseS[j])
                {
                    //动态规划
                    if (i == 0 || j == 0)
                    {
                        store[j] = 1;
                    }
                    else
                    {
                        store[j] = store[j - 1] + 1;
                    }
                }
                else
                {
                    store[j] = 0;
                }
                if (store[j] > maxLength)
                {
                    //判断比较的字符串是不是来源自同一个字符串
                    int preJ = sSize - 1 - j;
                    int nowJ = preJ + store[j] - 1;
                    if (nowJ == i)
                    {
                        end = i;
                        maxLength = store[j];
                    }
                }
            }
        }

        result = s.substr(end + 1 - maxLength, maxLength);
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/ef62f9f957b8bb8ff29f10b123454cdb58d7098bd067581c283ab21860aca223-1.jpg),![2.jpg](https://pic.leetcode-cn.com/637ccb25a0bff6565e3e94d8ec25a2d5528449215cd10c883d94eacb62d6c0a9-2.jpg),![3.jpg](https://pic.leetcode-cn.com/6d29efc2c32e6a9ddac9f1c46a2604526dfbe668802a31271e44329ef79afed2-3.jpg),![1.jpg](https://pic.leetcode-cn.com/03e47e70fd4b79a61ef4db9b3611d82c58806691f2e0a8eea4fad7e861d56ffc-1.jpg),![2.jpg](https://pic.leetcode-cn.com/2908623f14178c469521da420df84247c2bc097afb70a3ffc365248455985d8c-2.jpg),![3.jpg](https://pic.leetcode-cn.com/195416fa373dcfe54f36d1b6b25dd1e9900295f128054b96d3a6ac393058422c-3.jpg)>

```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //判断空字符串的情况
        if (s == "")
        {
            return "";
        }
        string result("");
        int sSize = int(s.size());
        vector<bool> tmpVec(sSize, false);
        vector<vector<bool>> store(sSize, tmpVec);
        int start = 0, end = 0, maxLen = 0;
        //动态规划 store[i][j]
        for (int len = 1; len <= sSize; len++)
        {
            for (int i = 0; i < sSize; i++)
            {
                int j = i + len - 1;
                if (j >= sSize)
                {
                    break;
                }
                //长度为1，2的情况单独考虑
                store[i][j] = (len == 1 || len == 2 || store[i + 1][j - 1]) && s[i] == s[j];
                if (store[i][j] && (j - i + 1) > maxLen)
                {
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }

        result = s.substr(start, end - start + 1);
        return result;
    }
};
```
```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //判断空字符串的情况
        if (s == "")
        {
            return "";
        }
        string result("");
        int sSize = int(s.size());
        vector<bool> store(sSize, false);
        int start = 0, end = 0, maxLen = 0;
        //动态规划 store[i] 从上层向下层循环
        for (int j = 0; j < sSize; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                //长度为1，2的情况单独考虑
                store[i] = (s[i] == s[j] && (j - i < 3 || store[i + 1]));
                if (store[i] && (j - i + 1) > maxLen)
                {
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }

        result = s.substr(start, end - start + 1);
        return result;
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/368566ef84257f7255b3fef3771d19e68387010454f3c8e19ce65bf064c5a542-1.jpg),![2.jpg](https://pic.leetcode-cn.com/818ee8b6803ef09150266fc7beb27d88df0fddce2ebe74f311f6eb09216c34a1-2.jpg),![3.jpg](https://pic.leetcode-cn.com/3725db3f997732bdd61a6ab8d16f3db818b17a9eefd0944e8ac94693f34313da-3.jpg),![1.jpg](https://pic.leetcode-cn.com/ac4bfbd1f8d7737e32a36753cbc26ee574dc401bab4b38516a7a435b22d997b1-1.jpg),![2.jpg](https://pic.leetcode-cn.com/ff2697ece60e16cc271b743075358dd04e8d6497e865d24de8382c53dae8bb34-2.jpg),![3.jpg](https://pic.leetcode-cn.com/2acbcfca69a6771e0003cf66926a0598bf0025f615da712d2a541a3c3430c482-3.jpg),![4.jpg](https://pic.leetcode-cn.com/64911cdf93b5a667f56a3c8e8a353f5a8c0962d3aca49ba38f3020db8258adf0-4.jpg),![5.jpg](https://pic.leetcode-cn.com/3be856e21166d26d4dd0dfca79d3a90c8d28a0a80d299421b7da2ad056b5b9fb-5.jpg),![6.jpg](https://pic.leetcode-cn.com/f84b3aacc6243581ca96ffe0ea6d9445d7d72d6dd1f42126fe607396af68360f-6.jpg),![7.jpg](https://pic.leetcode-cn.com/fa7080be5e5786369577e3b415a8bd8789f1d81b3180a78b0b65e4c865a0279a-7.jpg),![8.jpg](https://pic.leetcode-cn.com/0732b49a83dffc352d258776fbb2a0f34a1d80c6c4bb92501e83d37ed1b42b4f-8.jpg),![9.jpg](https://pic.leetcode-cn.com/092d8bef19a92e34eaf90f76030bdc412ffd384ba9ba05c07f147b324bba398e-9.jpg),![10.jpg](https://pic.leetcode-cn.com/4d2faa2193b3815155e147c104ed331508230af06a2fe9c764ea3c71ad63ea4d-10.jpg),![11.jpg](https://pic.leetcode-cn.com/a65b613e33dc6a4ccc264a22cd31b42830fbe64c2a2e20fb6823e224f42a9ae6-11.jpg),![12.jpg](https://pic.leetcode-cn.com/6ee935a05832c60db5701634ecc9cda3152ca32c053c4d797983cb42b71f7d19-12.jpg)>

```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //判断空字符串的情况
        if (s == "")
        {
            return "";
        }
        string result("");
        int sSize = int(s.size());
        //选择一个中心点，向两侧扩展
        for (int i = 0; i < sSize; i++)
        {
            //奇数组情况
            string tmpStr = expandHelper(s, i, i);
            //偶数组情况
            string tmpStr2 = expandHelper(s, i, i + 1);
            if (int(tmpStr.size()) > int(result.size()))
            {
                result = tmpStr;
            }
            if (int(tmpStr2.size()) > int(result.size()))
            {
                result = tmpStr2;
            }
        }

        return result;
    }

    string expandHelper(string &s, int left, int right)
    {
        int sSize = int(s.size());
        while (left >= 0 && right < sSize && s[left] == s[right])
        {
            left--;
            right++;
        }
        //小心s[left] != s[right]
        return (s.substr(left + 1, right - left - 1));
    }
};
```

<![1.jpg](https://pic.leetcode-cn.com/53b27127a2be9a7872544f2f931f8747c0121caefbc20f4e29bc08241e2f02f2-1.jpg),![2.jpg](https://pic.leetcode-cn.com/21d816e0c0293602dade18e39e45ef6df2ccd7730bee9297e214faae052f1bd3-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b4cb9b5245142da0806369a2691f773ad71e2680011a3e935c294f7af8c70176-3.jpg),![1.jpg](https://pic.leetcode-cn.com/5e4b9fcc9dcb269309cc9c2799b0e6e4c551067cf59000caedec00ab34e28c84-1.jpg),![2.jpg](https://pic.leetcode-cn.com/3d6c2e28e384e19ede41205df62119cdefd649a9da0011444fef4e0ab2874c52-2.jpg),![3.jpg](https://pic.leetcode-cn.com/69fd59adaebc726ea8af72ac03652ecaa17a45a999b74335665a88a73ef5d07c-3.jpg),![4.jpg](https://pic.leetcode-cn.com/bafaa4d106c00d6b35b52176280c8f269906f417b419d78b7c14efd0c47bc73f-4.jpg),![5.jpg](https://pic.leetcode-cn.com/8b5d967b4bf8c7b08273ef7c43a00c434e682788dd0ecab0b1cf4aa25a1e54aa-5.jpg),![6.jpg](https://pic.leetcode-cn.com/7ff080ec01eea35a62235c807edac2ead47f0e582ff904f3b76e7ff87221a712-6.jpg)>

```
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //预处理字符串
        string newS = preProcess(s);
        string result("");
        int newSSize = int(newS.size());
        vector<int> store(newSSize, 0);
        //c表示center，right表示右边界，store数组维护半径数组
        int c = 0, right = 0;
        //马拉车算法
        for (int i = 1; i < newSSize - 1; i++)
        {
            int iMirror = 2 * c - i;
            if (right > i)
            {
                store[i] = min(store[iMirror], right - i);
            }

            //这里有[-1]和[+1]操作。因此要小心越界。开始的循环内要留有空间，开头和结尾的#不要。
            while (newS[i - store[i] - 1] == newS[i + store[i] + 1])
            {
                store[i]++;
            }
            if (i + store[i] > right)
            {
                c = i;
                right = c + store[i];
            }
        }

        int maxLen = 0, maxCenter = 0;
        for (int i = 0; i < newSSize; i++)
        {
            if (store[i] > maxLen)
            {
                maxLen = store[i];
                maxCenter = i;
            }
        }
        int start = (maxCenter - maxLen) / 2;
        result = s.substr(start, maxLen);

        return result;
    }

    string preProcess(string &s)
    {
        if (s == "")
        {
            return "^$";
        }
        string tmpStr = "^";

        int sSize = int(s.size());
        for (int i = 0; i < sSize; i++)
        {
            //不能写成a += b + c，字符串多次相加只能用a = a + b + c操作
            tmpStr = tmpStr + "#" + s[i];
        }

        tmpStr += "#$";
        return tmpStr;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/677843f28ab376b3cee59ca69c072039fa83651ec6e0b11bdb540d3e4334aaaa-%E7%BB%93%E5%B1%80.jpg)
更多内容可以看我制作的视频
https://www.bilibili.com/video/av75124283



