class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.length()!=b.length())//长度不相等，直接返回最长的字符串
            return max(a.length(),b.length());
        else //长度相等时
        {
            if(a==b)//内容完全一样时
                return -1;
            else//内容不一样时
                return a.length();//随便返回一个字符     
        }
        return 0;
    }
};