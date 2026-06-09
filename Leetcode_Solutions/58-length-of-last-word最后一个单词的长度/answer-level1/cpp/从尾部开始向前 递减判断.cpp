```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int num=0,i=0;
        int n=s.size();//先计算出这个字符串的长度
        while(s[n-1-i]==' '&&(i<n))//从后面开始 移到最后一个字母出现的位置
            i++;
            while(s[n-1-i]!=' '&&(i<n)){//上面已经出现了字母  现在需要移动到最先出现空格的地方
                num++;
                i++;
            }
        return num;                    
    }
};

```
