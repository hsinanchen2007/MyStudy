```
class Solution {
public:
    string longestPalindrome(string s) {
        int maxleft=0,maxright=0,left,right;//分别用于记录最终结果的左右两端与当前子串的左右两端

        if(s.size()==0){//若长度为零,返回空字符串
            return {};
        }
        //分别以各个字符或空位为中心求回文子串
        for(int i=0;i<s.size()-1;++i){
            //当以前后相邻两元素为base情况
            if(s[i]==s[i+1]){
                left=i;
                right=i+1;
                //若此子串外侧两元素依旧相等则继续扩增
                while(left>0&&s[left-1]==s[right+1]){
                    left--;
                    right++;
                }
                //maxright-maxleft此前记录最长回文子串长度,若当前子串长于此则取代
                maxleft=((maxright-maxleft)>(right-left))?maxleft:left;
                maxright=((maxright-maxleft)>(right-left))?maxright:right;
            }
            //当以三个元素为base情况,无需对倒数第二个元素求该情况
            if(s[i]==s[i+2]&&i<s.size()-2){
                left=i;
                right=i+2;
                while(left>0&&s[left-1]==s[right+1]){
                    left--;
                    right++;
                }
                maxleft=((maxright-maxleft)>(right-left))?maxleft:left;
                maxright=((maxright-maxleft)>(right-left))?maxright:right;
            }
        }
        string result;
        for(int i=maxleft;i<=maxright;++i){//通过添加元素生成最终结果
            result.push_back(s[i]);
        }
        return result;
    }
};
```