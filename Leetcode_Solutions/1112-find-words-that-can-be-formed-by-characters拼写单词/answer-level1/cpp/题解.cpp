### 解题思路
先将其存储在map数组当中 其中tmp是保存map中键值对的信息 记录chars里各个字母的个数 扫描一遍字符串，出现字符就对应的减1如果发现其小于等于0说明这个单词未被掌握

### 代码

```cpp
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int> ma;
        map<char,int> tmp;
        bool flag;
        int ans = 0;
        for(int i = 0; i < chars.size(); i++){
            ma[chars[i]]++;
        }
        tmp = ma;
        for(int i = 0; i < words.size();i++){
            flag = true;
            for(int j = 0;j < words[i].size();j++){
                if(ma[words[i][j]] > 0)
                ma[words[i][j]]--;
                else{
                    flag = false;
                    break;
                }
            }
            ma = tmp;
            if(flag){
                ans = ans + words[i].size();
            }
        }
        return ans;
    }
};
```