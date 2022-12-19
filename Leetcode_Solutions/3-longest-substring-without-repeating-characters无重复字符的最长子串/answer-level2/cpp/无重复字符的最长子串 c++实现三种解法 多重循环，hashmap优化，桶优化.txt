![3.mp4](43100409-d745-457f-9d76-1aca49b474a7)

<![1.jpg](https://pic.leetcode-cn.com/36b384770aa8260fca7a9613d9782fec2efeca5282e5f002e610330062ed6865-1.jpg),![2.jpg](https://pic.leetcode-cn.com/55f2f06814078e753f347a72722ebb835b4f81aafd56aa7449819a9d933590c2-2.jpg),![3.jpg](https://pic.leetcode-cn.com/10c1ff70bfc92e52f52fcc858eb60e157d3d8e3ff0abce98d3677462b98cfedb-3.jpg),![1.jpg](https://pic.leetcode-cn.com/d7a5c09ca134fed8250408fb1bbde0032ae4ecc45a1be3133e5c1855bcb2bbe7-1.jpg),![2.jpg](https://pic.leetcode-cn.com/c94cc222f6d272a20c72e9eb23bf664f8967f38bd6c53d0b396c82e2951b27b5-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c10a1b15727ca49bf991690c40eb5db94a9199a81a8162f86a7f0f283ad8198b-3.jpg),![4.jpg](https://pic.leetcode-cn.com/d5aba4bfea1d0b0d6fc31fb6cefd8b2e5489bcf7e1b77b81cc74cea3ec7c5853-4.jpg),![5.jpg](https://pic.leetcode-cn.com/215d944bde59087836aa4f5aad4514177fd1acc9707386413e40678a8406262e-5.jpg),![6.jpg](https://pic.leetcode-cn.com/3acbd78605394f8dbf3ce96f25867e73851837224ef65596ad354500b0e3a181-6.jpg)>
### 代码：
```
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        while (end < sSize)
        {
            char tmpChar = s[end];
            for (int index = start; index < end; index++)
            {
                if (tmpChar == s[index])
                {
                    start = index + 1;
                    length = end - start;
                    break;
                }
            }

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
```
<![1.jpg](https://pic.leetcode-cn.com/cf3b3876b36f0b110a2f9cf75b8d25f8d46ca2d354c10a4592cb40ee7ab696ba-1.jpg),![2.jpg](https://pic.leetcode-cn.com/5e4b540c500ba603b0e4fbc6fd43069d23aca5493020462d35553dcf627973c5-2.jpg),![3.jpg](https://pic.leetcode-cn.com/b2f2ab0b459e0a813aff0a415901a8f45c857764e0b142c14a9e1362c0f6b82f-3.jpg),![1.jpg](https://pic.leetcode-cn.com/f89b4d10bb19d593712b227d83888aaac30e9446638d859571dec1be9267036b-1.jpg),![2.jpg](https://pic.leetcode-cn.com/d294dba31dfbb6aab76bb1cc88c61309dbf89c381eb16e88c112a3ee0355d78c-2.jpg),![3.jpg](https://pic.leetcode-cn.com/c05ff28d8880b621ec37cae20971d57f316547d67ad10dd8b1b6a5e7b87da1f8-3.jpg),![4.jpg](https://pic.leetcode-cn.com/ce6cea37297b02adb5a235e21d81b599352c246d201da89ddbf4ad3c860f840e-4.jpg),![5.jpg](https://pic.leetcode-cn.com/ccf332e8a8d799a47250709f86bfa0d3d635ef789018f7f3245a4e28b8e37ce3-5.jpg)>
### 代码：
```
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
```
<![1.jpg](https://pic.leetcode-cn.com/ffba20473b384209f08d76c25437a6ac32a21323ce375caeeb7dd38ce625ae11-1.jpg),![2.jpg](https://pic.leetcode-cn.com/7ff9da97366a7b8616bab2e165e5e12dcdda5e4447ba2dadb7e3aafc8cd8cba4-2.jpg),![3.jpg](https://pic.leetcode-cn.com/489387f6bf40d7478b870e7a47ff95092cb7e1c766a13ecd23ab2f4d4cf18707-3.jpg),![1.jpg](https://pic.leetcode-cn.com/a0bf3c10dd3618827ecc22f4d81ca97a184b73c6e3a0c61a9a802deb4ca119a8-1.jpg),![2.jpg](https://pic.leetcode-cn.com/64dc3a5f7940b17810bd2f378fba048154c956b07a84fa3f7e23452c3831735b-2.jpg),![3.jpg](https://pic.leetcode-cn.com/f87214921228ca2180133548bdfc0aa4db8308be565a8e340f502bbc88696b07-3.jpg),![4.jpg](https://pic.leetcode-cn.com/b2930660922e0d5464456c157bcd874a5346fe1fe34a920ee28e13d5c827a4f3-4.jpg),![5.jpg](https://pic.leetcode-cn.com/5e5ff7360edaaf14a73db9aaa63cc769ac20ad0fa6ca95629a9df8b942da0a1f-5.jpg),![6.jpg](https://pic.leetcode-cn.com/2c2b207aaed4c58b790867b717614dcbac1cbae8cdaaf566d70cc1dc21ccd942-6.jpg)>
### 代码：
```
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        vector<int> vec(128, -1);
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (vec[int(tmpChar)] >= start)
            {
                start = vec[int(tmpChar)] + 1;
                length = end - start;
            }
            vec[int(tmpChar)] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
```
![结局.jpg](https://pic.leetcode-cn.com/186b3d071da47ea1cbe797659f1bc97f1ab1392fd6c244aac990b3bcdd63062d-%E7%BB%93%E5%B1%80.jpg)





