### 解题思路
1. 先建立个数组，把chars的字母全记录下来，'a'有几个，num[a]就是几。
2. 再搞个tmp复制一下（因为要多次使用）
3. 遍历words每个单词，比如a每出现一次tmp[a]--，如果tmp[a]==0，直接break，去找下个单词。
4. 如果这个单词结束也没break，cnt记录的长度加给ans
5. return ans
![image.png](https://pic.leetcode-cn.com/2717409ff7a0d9f87d242f7113526b00ac786f6fb4ed14d49f5e949a81e6b869-image.png)

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> num(256,0),tmp(256,0);
        for(int i=0;i<chars.size();i++)
        {
            num[chars[i]]++;
        }
        int cnt,ans=0;
        for(int i=0;i<words.size();i++)
        {
            cnt=0;tmp=num;
            for(int j=0;j<words[i].size();j++)
            {
                
                if(tmp[words[i][j]]!=0){
                    cnt++;
                    tmp[words[i][j]]--;
                }
                else break;
                if(j==words[i].size()-1)
                {
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};
```