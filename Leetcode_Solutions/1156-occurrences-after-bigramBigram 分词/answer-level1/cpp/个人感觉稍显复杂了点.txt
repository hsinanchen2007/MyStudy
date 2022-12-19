### 解题思路
没什么思路，单纯为了降低点内存消耗
### 代码

```cpp
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {

        string word;
        vector<string> words;
        vector<string> res;
        int count=-23;
        int index =0;
        int mutex =0;
        for(int i =0;i<text.size();i++)
        {
             word = "";
             while(i<text.size()&&text[i]!= ' ')
             {
                 word+=text[i];
                 i++;
             }
             index++;//记录单词次序
             if(word.size() != 0)
             {
                 //判断是否是第三个单词
                if(mutex == 1&&count+2 == index)
                 {
                     res.push_back(word);
                     mutex = 0;
                 }
                 //是否是第一个单词
                 if(word == first)
                 {
                    count = index;
                 }
                 //是否是第二个单词
                 else if(count+1 == index&&word == second)
                 {
                     mutex =1;
                 }
                
             }
        }
           
        return res;
    }
};
```