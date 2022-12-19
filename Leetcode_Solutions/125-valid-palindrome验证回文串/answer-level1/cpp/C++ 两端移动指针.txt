两端移动指针，找到首尾的有效字符然后进行比较，直到有一对不相等返回false，或头指针大于尾指针——表示全部检查完成，则返回true

代码有点啰嗦，性能中上
8ms	84.78%	9.3MB	75.05%

class Solution {
public:
    bool isText(char ch){ // 判断是否为有效字符
        if ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
            return true;
        else return false;
    }
    bool isPalindrome(string s) {

        int head = 0;
        int tail = s.size()-1;
        while (head < tail){
            //从两头同时移动指针，找到有效字符
            while (head<tail && !isText(s[head])) ++head;
            while (head<tail && !isText(s[tail])) --tail;
            //转小写
            if (s[head]>='A' && s[head]<='Z') s[head]=tolower(s[head]);
            if (s[tail]>='A' && s[tail]<='Z') s[tail]=tolower(s[tail]);
            if (s[head]!=s[tail]) return false;
            ++head;
            --tail;
        } 
        return true;   
    }
};