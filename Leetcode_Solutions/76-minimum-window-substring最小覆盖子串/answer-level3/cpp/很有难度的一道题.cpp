### 解题思路
初看以为挺简单，写着代码发现不简单，等提交发现自己的方法超时了，参照题解的思路重新写了下。

1.算法是滑动窗口，通过left和right两个指针控制匹配的字符串，先固定left，增加right直到匹配成功，再尝试增加left缩减所需的字符串，当不满足匹配时，再尝试增加right，循环下去。
2.判断是否匹配的方法也比较好，通过定义两个字典比较匹配情况，很精髓的只有元素个数相同才算做完全匹配一个字符。
代码虽短，精髓很多，还需努力。

### 代码

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int match = 0;
        int minlen = s.size()+1;
        int start = 0;
        string res;
        unordered_map<char, int> maps;
        unordered_map<char, int> mapt;
        
        for(char c:t) mapt[c]++;
        while(right<s.size()){
            if(mapt.count(s[right])) {
                maps[s[right]]++;
                if(maps[s[right]]==mapt[s[right]]) match++; //这个相等很精髓
            }
            if(match==mapt.size()){
                while (match==mapt.size()) {
                    if(right-left+1<minlen){
                        minlen = right-left+1;
                        start = left;
                    }
                    if(mapt.count(s[left])){
                        maps[s[left]]--;
                        if(maps[s[left]]<mapt[s[left]]){
                            match--;
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        return minlen<s.size()+1? s.substr(start,minlen): "";
    }
    // void print(unordered_map<char, int> map){
    //     for(unordered_map<char, int>::iterator iter=map.begin();iter!=map.end();iter++){
    //         cout<<iter->first<<' '<<iter->second<<endl;
    //     }
    // }
};

```