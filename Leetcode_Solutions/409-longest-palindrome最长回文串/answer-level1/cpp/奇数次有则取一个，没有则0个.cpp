打卡迟到了。呜呜
哈希啦，遍历字符串，把字母对应数字作为下标，用letters保存该下标对应字母的出现次数。
用s的字符组成回文字符串，出现次数为偶数的肯定用得上，而出现次数为基数的，只能用一个，所以就遍历一下letters，统计出现奇数次的字符有几个，若至少有一个，那么这一个+偶数次的就是总长度，若没有奇数次的字符，那么偶数次的就是回文字符串的总长度。

```
class Solution {
public:
    int longestPalindrome(string s) {
        int ss = (int)s.size();
        vector<int> letters(128,0);//大小写ASCII128个
        for(char c:s){
            letters[(int)c]+=1;
        }
        int out = 0;
        for(int i=0; i<128; i++){
            if(letters[i]%2==1){
                out++;
            }
        }
        if(out>0){out--;}
        return ss-out;
    }
};
```
