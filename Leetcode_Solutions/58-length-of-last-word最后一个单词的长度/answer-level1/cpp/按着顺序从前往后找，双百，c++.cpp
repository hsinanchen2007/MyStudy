# 思路
没有技巧，就从前往后找，每一个空格前计数sum，到空格计数清零sum=0。如果最后不是以空格结尾，那个sum就是最后一个单词的长度。
但如果是以空格结尾的最后一个单词怎么办呢？用一个变量tmp临时保存每次空格前的计数。最后验证sum和tmp，如果tmp不为0，sum为0，那么就是以空格结尾了，输出tmp就行。
# 代码
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sum = 0;
        int tmp = 0;
        if(s.size()<1) return 0;
        for (char i:s){
            if(i != ' '){
                sum++;
                tmp = sum;
            }
            
            else sum=0;
        }
        if(sum==0 && tmp!=0) return tmp;

        return sum;
    }

};
```
