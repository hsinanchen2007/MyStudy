![捕获.PNG](https://pic.leetcode-cn.com/85cdab946f0280b36a7fde95dc5c417a72c834899fa445f82a67a9d320ec7356-%E6%8D%95%E8%8E%B7.PNG)
**思路：** 
    每个单词反转，再整体反转。

class Solution {
public:
    string reverseWords(string s) {
        int k = 0,n=s.size(),j;
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            if(k){
                s[k++]=' ';  
            }
            j=i;
            while(j<n && s[j]!=' '){
                s[k++]=s[j++];
            }
            reverse(s.begin()+k-(j-i),s.begin()+k);
            i=j;
        }
        s.resize(k);
        reverse(s.begin(),s.end());
        return s;
    }
};