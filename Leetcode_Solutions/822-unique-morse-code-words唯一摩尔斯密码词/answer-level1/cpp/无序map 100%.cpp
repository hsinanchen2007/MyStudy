### 解题思路
![NCBFQ}9_7O6$0JE2MOGUV$2.png](https://pic.leetcode-cn.com/5311e460034ee3fc768fbf0887d9dbac2ea78d00d3e1990e55c492002a63ae4a-NCBFQ%7D9_7O6$0JE2MOGUV$2.png)


### 代码

```cpp
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<string,int> res;
        string refer[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.size();i++)
        {
            string c="";
            for(int j=0;j<words[i].length();j++)
                c+=refer[words[i][j]-'a'];
            res.insert(pair<string,int> (c,1));
        }
        return res.size();
    }
};
```