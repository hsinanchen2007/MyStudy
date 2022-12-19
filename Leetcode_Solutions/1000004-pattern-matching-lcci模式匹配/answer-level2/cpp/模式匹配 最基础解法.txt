### 思路

#### 分情况讨论
1. **pattern 为空 null**
    若 value 不为空，那么没法匹配成功
2. **pattern 纯净 pure** 
    即 pattern 为`'aa..a' or 'bb...b'`, 那么只需要等切分 value，检验各个子串是否相同
3. **pattern 多配一 multi-single**
    即 pattern 为`'a..aba..a' or 'b..bab..b'`, 单个'a'或'b'在整个字符串中的位置不定，这种情况下，只需要假设单个字符为为 value 整串，存在多个的字符代表空串。这种结构必然可以完成匹配。
> 举个例子🌰：pattern:"aaabaa", value: "cjdusncuwcuhslughusahfuelfuh"
> 我们大可以让 'a' <=> "", 'b' <=> "cjdusncuwcuhslughusahfuelfuh"
4. **其他情况 general**
    最一般的匹配搜素，不断尝试**不同**的子串，直到找到合理的匹配。


### 代码
```cpp
class Solution {
public:
    bool patternMatching(string pattern, string value) {
        // pattern null ("")
        if(pattern.length() == 0 ){
            return value.length() == 0;
        }

        int cnt[2] = {0, 0};
        for(char c: pattern) {
            cnt[c - 'a'] ++;
        }
        int len = value.length();
        int multi = cnt[1] * cnt[0];

        // pattern: pure ('aa..a' or 'bb..b')
        if(multi == 0) { 
            if(len % pattern.length() != 0) {
                return false;
            }

            int sublen = len / pattern.length();
            string model = value.substr(0, sublen);
            for(int ptr = 0; ptr < len; ptr += sublen) {
                if(model.compare(0, sublen, value, ptr, sublen)) {
                    return false;
                }
            }
            return true;
        }
        
        // pattern: multi-single ('a..aba..a' or 'b..bab..b')
        if(multi == cnt[0] || multi == cnt[1]) {
            return value.length() != 0;
        }

        // general pattern
        string pattern_a = "-", pattern_b = "-";
        bool got_match = true;
        for(int la = 0; la < len; la++) {
            int remainder = (len - cnt[0] * la) % cnt[1];
            if(remainder) {
                continue;
            }
            
            int lb = (len - cnt[0] * la) / cnt[1];
            if(lb < 0) {
                continue;
            }
            
            int ptr = 0;
            pattern_a = "-", pattern_b = "-";
            got_match = true;
            for(char c: pattern) {
                if(c == 'a') {
                    if(pattern_a == "-") {
                        pattern_a = value.substr(ptr, la);
                    } else if(pattern_a.compare(0, la, value, ptr, la) ) {
                        got_match = false;
                        break;
                    }
                    ptr += la;
                } else {
                    if(pattern_b == "-") {
                        pattern_b = value.substr(ptr, lb);
                    } else if(pattern_b.compare(0, lb, value, ptr, lb) ) {
                        got_match = false;
                        break;
                    }
                    ptr += lb;
                }
            }
            
            if(got_match && pattern_a != pattern_b) {
                return true;
            }
        }

        return false;
    }
};
```

### 总结
这应该是最基础的解法了，感觉 pattern 为一般的情况下，匹配算法效率较差。
希望大家多提宝贵建议！🍺