#### 解题思路
一个非常丑陋的写法。
开了一个新的字符串，预设为与s一样大。
从后向前遍历s，找到第一个不为空格的位置，记录为end，再向前找到第一个为空格的位置，取该位置后面的位置，即单词的开头。将找到的单词拷贝到新开设的字符串中。
采用memcpy的方式拷贝字符，所以效率比较高，就是代码看起来有点丑。

#### 代码
```c++
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        res.resize(s.size());
        int index = 0; // 记录res字符串当前写入的位置
        int end = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            while(i >= 0 && s[i] == ' '){ // 从后向前找到第一个不为空格的位置
                i--;
            }
            end = i;
            while(i >= 0 && s[i] != ' '){ // 继续向前找到第一个为空格的位置
                i--;
            }
            if(i >= -1){
                if(end < 0) return res; // 已经到头，且不存在不为空格的位置，大功告成
                if(index != 0){
                    res[index] = ' '; // 如果不是开头， 就加个空格
                    index++;
                }
                memcpy(&res.at(index), &s.at(i+1), end-i); // 拷贝
                index += (end-i); // 更新当前res字符串的大小
                end = i;
            }
        }
        res.resize(index);
        return res;
    }
};
```

#### 比较
想试试原地翻转，就试了一下使用reverse方法，先将整个字符串反转，再逐个词反转，再去掉多余空格的方法。
慢很多，12ms。我的原方法在0ms。不过未尝不是一个思路。