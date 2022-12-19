```cpp []
/**
* 思路：滑动窗口，每次检查窗口的下一个字符是否和窗口中的字符重复，若重复，则将窗口的左侧直接跳到重复字符的下个位置处
* 伪代码：
*   起始索引 = 0
*   新建hash表
*   遍历字符串
*   若hash表中无重复字时：
*     将字符放入hash表中，表内记录索引
*   若hash表中有重复字时：
*     maxlen = max(maxlen, 此处索引 - 起始索引);
*     起始索引 = hash表中重复字的索引 + 1
*     并覆盖hash表重复字的索引为当前索引
*   遍历完成后，返回maxlen
**/

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int headIndex = 0;
        int hashmap[256];
        memset(hashmap, -1, sizeof(hashmap));
        int index = 0;
        for(unsigned char c : s) {
            if(hashmap[c] >= headIndex) {
                res = std::max(res, index - headIndex);
                headIndex = hashmap[c] + 1;
                // 若剩余字串长度已经小于等于res，则不用继续遍历，直接返回res
                if(s.size() - headIndex <= res)
                    return res;
            }
            hashmap[c] = index++;
        }
        return std::max(res, index - headIndex);
    }
};

int main()
{
    string str = "abcbaacebca";
    Solution s;
    auto len = s.lengthOfLongestSubstring(str);
    cout << "Length of longest sub string is " << len << endl;
    return 0;
}

```
```python []
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashmap = {}
        windowLeft = 0
        res = 0
        for i, c in enumerate(s):
            if (hashmap.get(c) is not None) and windowLeft <= hashmap[c] :
                res = max(res, i - windowLeft)
                windowLeft = hashmap[c] + 1
                if len(s) - windowLeft <= res :
                    return res
            hashmap[c] = i
        return max(res, len(s) - windowLeft)


if __name__ == "__main__":
    teststr = "acdacddacda"
    s = Solution()
    maxLen = s.lengthOfLongestSubstring(teststr)
    print("length of longest substring is %d" %(maxLen))

```
```c# []
using System;
using System.Collections;

namespace LeetCode_0003
{
    public class Solution
    {
        public int LengthOfLongestSubstring(string s)
        {
            int left = 0;
            int res = 0;
            Hashtable hashtable = new Hashtable();
            int index = 0;
            foreach (var c in s)
            {
                if(hashtable.ContainsKey(c) && Convert.ToInt32(hashtable[c]) >= left) {
                    res = res > (index - left) ? res : (index - left);
                    left = Convert.ToInt32(hashtable[c]) + 1;
                    if(s.Length - left <= res)
                        return res;
                }
                hashtable[c] = index++;
            }
            return res > (s.Length - left) ? res : (s.Length - left);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string testStr = "acddc";
            var s = new Solution();
            Console.WriteLine($"Length of longest substring is {s.LengthOfLongestSubstring(testStr)}");
        }
    }
}

```