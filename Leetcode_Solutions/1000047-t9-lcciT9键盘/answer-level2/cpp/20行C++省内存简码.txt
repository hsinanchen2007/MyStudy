### 解题思路
1. 首先用一个字符串数组存放每个按键的字母
2. 第一个for循环取出words容器的单词，第二个for循环取出其中的字母
3. 用zfc表示第几个按键的字符串，如果从for循环中取出的字母在该字符串中，count++
4. 最后看count是否和words单词长度一样，若一样则表示每一个都存在zfc中，此时加入到vector中


![image.png](https://pic.leetcode-cn.com/a6eb0c58342e328e26a0ca78cf8fcef82b8552917ce13c4c750595461a55c4be-image.png)


### 代码

```cpp
class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> svec;
        string letters[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int count = 0;
        string zfc;
        for(int i = 0; i < words.size(); i++){				// adm	deo	 vam  fan
            for(int j = 0; j < words[i].size(); j++){		// a d m
                zfc = letters[num[j]-'0'];
                if(zfc.find(words[i][j])!=zfc.npos) count++;		// 如果找得到 
            }
            if(count==words[i].size()) 
                svec.push_back(words[i]); 
            count = 0;
        }
        
        return svec;
    }
};

```