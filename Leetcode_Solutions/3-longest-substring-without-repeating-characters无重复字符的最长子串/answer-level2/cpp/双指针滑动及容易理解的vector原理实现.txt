### 利用vector容器
**思路**
- 原理与双指针相同，要好理解一些。
- 用一个vector来保存当前无重复子串对象，对字符串的每一个字符与vector中的所有内容进行比较。
- 无重复则将字符存入vector末尾，有重复则检验并更新最大长度，再将vector中那个重复的字符及其之前的内容删掉。

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        vector<char>str;
        int mlen=0;
        //扫描string s
        for(int i=0;i<n;i++){
            char c = s[i];
            //扫描vector str
            for(int m=str.size()-1;m>=0;m--){
                if(c==str[m]){
                    //更新mlen
                    if(mlen<str.size())
                        mlen = str.size();
                    //删除重复字符及其之前的字符
                    str.erase(str.begin(),str.begin()+m+1);
                    break;
                }
            }
            str.push_back(c);
        }
        if(mlen<str.size())
            mlen=str.size();
        return mlen;
    }
        
};
```

### 双指针滑动
**思路**
- 用【头指针】指向s[0]，【尾指针】end指向s[1]，作为开始，循环找无重复子串。
- 每一次循环扫描头、尾指针之间的这个子串，流程大概是这样：
    - 无重复，【头指针】原地踏步【尾指针】前进一步。
    - 有重复，将【头指针】立定跳到重复字符+1的位置，检验更新最值为[pre,end)区间长度，【尾指针】前进一步。
- 这样【头指针】新位置之前的字符不用再扫描，因为那里已经出现了重复字符，它的长度也判断过了。

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        // 字符串长度为0、1时直接返回数字，双指针没有地方指。
        if(!len) return 0;
        if(len==1) return 1;
        // 头指针pre，尾指针end，最大长度max至少为1。
        int pre=0,end=1;
        int max=1;
        for(;end<len;++end){
            for(int cur=pre;cur<end;++cur){
                // 有相同字符时，头指针pre更新，检查并更新最大长度max。
                if(s[cur]==s[end]){
                    if(max<(end-pre)) max=end-pre;
                    pre=cur+1;
                    break;
                }
            }
        }
        // 考虑到字符串里没有重复字符，再检查并更新最值。
        if(max<end-pre)
            max=end-pre;
        return max;
    }
};
```
