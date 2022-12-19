这题，是先对字符串`T`进行预处理，用数组`map_`记录下每个字符的个数。比如`ABC`，得到的数组是 **`map_[A]=1, map_[B]=1, map_[C]=1`**，将字符串t长度记为`all`。

```
S 	： A D O B E C O D E B A  N  C
下标： 0 1 2 3 4 5 6 7 8 9 10 11 12
	   ^
	   L/R
```
一开始双指针`L/R`都是指着开始位置，`R`负责扩大`[L,R]`之间的窗口，`L`负责缩小`[L,R]`之间的窗口。`R`每到一个位置都是进行 `map_[t[R]]--`。如果 `map_[t[R]] >=0`，那么相应的`all--`。这是因为，只有一开始在 `map_`中存在的正数只有`t`中的字符，只有遇到这些字符并且在  `map_[t[R]]--`后才有可能满足 `map_[t[R]] >=0`，随之`all--`。
```cpp
     --map_[str[right]];

    if(map_[str[right]] >=0) 
    { 
        --all;
    }
```
当`all==0`时，即说明已经在`s`中全部遇到了`t`中的字符。`all==0`说明 **以当前 `L` 位置开始的子串中**，满足包含`t`中所有字符的最短字串就是`[L,R]`区间。

下一步操作是`L++`，即在 `[L,R]` 区间寻找以 `R` 结束的字串中满足条件的更短的字串`[L',R]`。在 `L` 右移动的过程中，需要 `map_[t[L]]++` ，表示将当前`L`字符移出`[L.R]`范围。一直移动到 `map_[t[L']] ==0`，此时`s[L]`肯定是`t`中的一个字符，因为只有 `s`中的字符才有可能是0，那么此时计算`[L,R]`之间的长度：`R-L+1`。 

为什么此时才计算长度？ 

`[L, L')` 区间的字符 `map[s[L]] < 0` 说明，要么是 `s[L]` 不是 `t`中的字符，要么就是 `s[L]`是 `t`中字符，但是`s`中包含了多个，即在 `[L',R]` 之间还有`s[L]`，因此可以将当前这个忽略。 当遇到  `map_[t[L']] ==0` 时，说明 `L'`处的字符，在`s`中，且 `[L', R]`只包含一个。 

到次，一次迭代结束，下次迭代重复上述步骤。
```cpp
class Solution {
public:
    std::string minWindow(std::string str, std::string pattern) {
        if(str.empty()) return "";

        int map_[256]; ::memset(map_, 0, sizeof(map_)); 
       
        for(const auto& Ch : pattern) {
            ++map_[Ch];
        }

        int all = pattern.length(); 
        int left =0, right=0;   
        int minLen =INT_MAX, minPos=0; // 记录位置

        while(right < str.length()) {   
            --map_[str[right]];

            if(map_[str[right]] >=0) 
            { 
                --all;
            }

            if(all ==0) { 
                while(map_[str[left]] < 0) { 
                    ++map_[str[left]];
                    ++left;
                }

                int newLen =  right - left +1;
                if(minLen > newLen) { 
                    minLen = newLen;
                    minPos = left;
                }
               
                ++map_[str[left]];
                ++all;
                ++left;
            }

            ++right;
        }  

        return minLen ==INT_MAX ? "" : str.substr(minPos, minLen);
    }
};

```
