### 解题思路
利用两个指针分别记录word1和word2的位置，若符合条件，更新最小值。一次遍历即可。

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
         int left= 0, right = 0, len =words.size();
         int ans = INT_MAX, flag = 0;  //ans记录结果，flag标识左边的字符串是word1还是Word2，flag为0标识左边没有匹配的字符串
         while(right < len)
         {
             if(words[right] == word1)
             {
                 if(flag == 2)
                 ans = min(ans, right - left);  //两个字符串类型不同，更新结果
                 flag = 1;
                 left = right;  //指针left右移至right
             }
             else if(words[right] == word2)
             {
                 if(flag == 1)
                 ans = min(ans, right - left);  //两个字符串类型不同，更新结果
                 flag = 2;
                 left = right;
             }
             right ++;
         }
         return ans;
    }
};
```