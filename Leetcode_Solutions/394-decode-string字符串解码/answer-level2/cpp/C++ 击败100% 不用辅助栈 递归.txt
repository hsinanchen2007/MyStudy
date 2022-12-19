思路：字符串有三部分
1、 数字[           例：3[
2、 字母]           例：abc]
3、 不在1,2中的字母  例：abc

递归思路：遇见数字就递归该数字后所匹配的[]，表达能力有点差，见代码注释吧。

class Solution {
public:
    int len = 0,pos = 0;
    string decodeString(string s) {
        string ans = "";
        len = s.size();
        while(pos < len)     //  因为放弃了辅助栈存储[]的位置，所以我们记录在程序当前时刻所走过的最远位置
            ans += dfs(s,pos);  
        return ans;
    }
    string dfs(string s, int i) {
        string temp = "", ans = "";
        int num = 0;
        for (; s[i]>='0'&&s[i]<='9'&&s[i] != '['; ++i)      //  求出要重复的数字大小，注意跳过没有数字的情况，
            num = num * 10 + s[i] - '0';
        if(s[i]=='['){                                   //  如果存在数字[的情况
            for (++i; s[i] != ']'; ++i) {                 // 在遇到]之前
                if (s[i] >= '0' && s[i] <= '9') {       //   如果还有数字，那就递归下一个位置
                    temp += dfs(s, i);                  
                    i = pos - 1;                        //  因为不知道刚才递归走了多少个]，索性我们直接到刚才走过的最远位置
                }
                else                                    //   累加字符
                    temp += s[i];
            }
            while (num--)                               // 重复
                ans += temp;    
            for (++i; i < len && s[i]>='a'&&s[i]<='z'; ++i)             // 注意还可能存在]abc3这种情况，不属于之前的[]也不属于下一个数字3[                 ans += s[i];           
        }
        else    
            for(;i<len&&(s[i]>='a'&&s[i]<='z');++i)      //  如何压根就没有数字[这种情况
                ans+=s[i];
        pos = max(pos, i);   // 更新走过的最远位置
        return ans;  

    }
};