class Solution {
public:
    int lengthOfLastWord(string s) {
        int search=s.size()-1;
        while(s[search]==' '&&search>=0)
        search--;
        int sum=0;
        while(s[search]!=' '&&search>=0)
        {
        search--;
        sum++;
        }
        return sum;

    }
};
从尾部开始搜索，时间复杂O（1），空间使用string原空间，没有额外空间