### 解题思路
一一比对即可，很简单的思路，但是方法很多，这里第一时间想到的是哈希表，但其实数组就可以，因为强调了小写字母，所以可以将mp替换为vector，这里仅仅是一个思路。

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int length=words.size();
        int len=chars.size();
        int count=0;
        for(int j=0;j<length;j++)
        {
            map<char,int> mp;
            for(int i=0;i<len;i++)
            {
                mp[chars[i]]++;
            }
            string tmp=words[j];
            int tlen=tmp.size();
            int sum=0;
            for(int k=0;k<tlen;k++)
            {
                
                if(mp[tmp[k]]>0)
                {
                    mp[tmp[k]]--;
                    sum++;
                }
                else
                {
                    sum=0;
                    break;
                }
            }
            count+=sum;
        }
        return count;
    }
};
```