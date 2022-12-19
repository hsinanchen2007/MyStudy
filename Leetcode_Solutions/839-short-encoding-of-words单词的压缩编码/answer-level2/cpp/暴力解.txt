### 解题思路
说白了就是： 看看一个词是否是另一个词的后缀，如果是，这个词就被压缩了，不计入长度

#。 长度小于自己的词不考虑
注意点: 多个完全相同的词， 因为彼此认为被压缩到其他词里，导致没有计入长度，这里采用第一个词发现后面有完全相同的词时，把后面的词置为空 “”

缺点：速度慢
优点： 空间好

### 代码

```cpp
class Solution {
public:

    bool isInOther(int w, vector<string>& words){
        string wd = words[w];
        int j;

        for (int i=0; i<words.size(); i++) if (words[i].size() >= wd.size() && w != i){
            // 比目标词 长的词中
            int begin = words[i].size() - wd.size() ;
            
            for (j=0; j<wd.size(); j++){
                if (words[i][begin+j] != wd[j])
                    break;
            }
            if (j == wd.size()){
                if (begin == 0)         // 连长度都是一样的 ==》完成相同
                    words[i] = "";      // 删掉这个词，避免重复
                else
                    return true;        // 不是完成相同的词，而是包含关系
            }
                
        }

        return false;
    }

    int minimumLengthEncoding(vector<string>& words) {
        int len = 0;
        // 如果词被包含在其他词的尾串里，则该词被忽略掉
        // 否则 len += 词.size()+1;
        for (int i=0; i<words.size(); i++){
            if (!isInOther(i, words))
                len += words[i].size() +1;
        }

        return len;
    }

};
```