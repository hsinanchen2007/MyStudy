### 解题思路
不使用额外空间，而使用l与r两个指针来表示最大回文子字符串的范围；

子回文字符串只可能中心是一个元素或中心两个元素。

故对于0~n-1范围内的元素，首先检查其是否符合s[i] == s[i + 1],如果符合则以s[i]s[i + 1]为中心使用临时变量lt = i - 1,rt = i + 1;并在符合字符串下标范围的情况下使用贪心算法扩大范围，不符合条件时记录count = rt - lt为该子字符串的长度并将l = lt + 1,r = rt - 1;更新l与r。

若不满足s[i] == s[i + 1],则以s[i]为中心赋予临时lt = i - 1, rt = i + 1;进行贪心算法；

每次进行子字符串计算之后比较当前子字符串长度与count的大小，如果大于count则更新l与r下标与count的值，这样遍历一遍后得到的就是最大的子字符串的两个指针l与r，输出s.substr(l, r - l + 1)即可

### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;      //一前一后两个指针用于标记最大回文
        int count = 0;  //用于更新最大回文长度
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){       //如果满足中心为两个相等的元素，则以两相等元素为中心向外求回文
                int lt = i - 1;
                int rt = i + 2;
                while(lt >=0 && rt < n && s[lt] == s[rt]){
                    lt--;
                    rt++;
                }
                if(rt - lt > count){
                    l = lt + 1;
                    r = rt - 1;
                    count = rt - lt;    //更新最大回文
                }
            }
            int lt = i - 1;
            int rt = i + 1;             //对于所有元素都以当前元素向外求回文
            while(lt >= 0 && rt <= n && s[lt] == s[rt]){
                lt--;
                rt++;
            }
            if(rt - lt > count){        //每次均进行判断此回文数是否比当前最大回文大
                l = lt + 1;
                r = rt - 1;
                count = rt - lt;        //若大则更新当前回文范围与回文长度
            }
        }
        return s.substr(l, r - l + 1);      //输出两个指针标记的最大回文数
    }
};
```