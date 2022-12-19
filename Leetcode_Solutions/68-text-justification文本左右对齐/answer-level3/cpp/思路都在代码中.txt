![image.png](https://pic.leetcode-cn.com/acc89de5ff82b23bf55b54551d0206915eabe86be5e1e9d7357d922ce13167a4-image.png)


### 解题思路
思路都在代码中

### 代码

```cpp
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> output;
    
    
    int currentLength = 0;
    int blankLength = 0;
    int beginIndex = 0;
    int lastWordsIndex = words.size() - 1;
    int wordsCount = 0;
    for (int index = 0; index != words.size(); index++) {
        //最后一个无论如何要添加
            int wordLength = words[index].length();
            int newLength = currentLength + wordLength;
            int newBlankLength = blankLength;
            if(wordsCount)
            {
                newBlankLength++;
            }
            if (newLength + newBlankLength > maxWidth || index == lastWordsIndex) {
                //将当前beginIndex和endIndex之间的单词创建字符串，并填入结果中
                //计算空格需要的长度
                bool needAddLastWord = false;
                bool isLast = false;
                if (index == lastWordsIndex) {
                    //连同最后一个单词一起加进去
                    
                    if (newLength + newBlankLength <= maxWidth) {
                        currentLength = newLength;
                        blankLength = newBlankLength;
                        wordsCount++;
                        isLast = true;
                    }
                    else
                    {
                        //最后一个单词需要直接添加进去
                        needAddLastWord = true;
                    }
                    
                }
                
                int totalBlankLength = maxWidth - currentLength;
                int largerBlandCount = 0;
                int averageBlankWidth = totalBlankLength / max(1,(wordsCount - 1));
                //剩余的空格数，先到先得，前面的单词每个加1个空格
                int remainBlankWidth = totalBlankLength % max(1,(wordsCount - 1));
                
                if (isLast) {
                    //最后一行需要左对齐
                    averageBlankWidth = 1;
                    remainBlankWidth = 0;
                }
                
                //添加第一个单词
                string result;
                
                result.reserve(16);
                
                for (int i = 0; i != wordsCount; i++) {
                    if (i) {
                        result.append(averageBlankWidth, ' ');
                        if (remainBlankWidth) {
                            result.append(1, ' ');
                            remainBlankWidth--;
                        }
                    }
                    result += words[i + beginIndex];
                }
                
                //仅有一个单词的情况下,添加结尾,对齐的最后一行添加结尾空格

                if (wordsCount == 1 || isLast) {
                    result.append(maxWidth - result.length(), ' ');
                }
                output.push_back(result);
                //若最后一个单词没有连同加进去，需要单独加进去。
                if (needAddLastWord) {
                    output.push_back(words[index].append(maxWidth - wordLength, ' '));
                }
                else
                {
                    currentLength = wordLength;
                    beginIndex = index;
                    blankLength = 0;
                    wordsCount = 1;
                }
                
            }
            else
            {
                //继续进行长度累加
                currentLength = newLength;
                blankLength = newBlankLength;
                wordsCount++;
            }
    }

    return output;

    }
};
```