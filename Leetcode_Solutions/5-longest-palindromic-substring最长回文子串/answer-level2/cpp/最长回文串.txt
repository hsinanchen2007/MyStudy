### 解题思路
暴力法
### 代码

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<1){
            return s;
        }
        string s1;
        int len = s.size();
        bool isPalindrome = false;
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(s[i]==s[j]){
                    int subStrLen = j - i + 1;
                    //cout << subStrLen << endl;
                    if(subStrLen>s1.size()){
                        //cout << s1.size() << endl;
                        if(judgePalindrome(s,i,j)){
                            //cout << i << " " << j << endl;
                            isPalindrome = true;
                            s1 = s.substr(i,subStrLen);
                            //cout << s1 << endl;
                        }
                    }
                }
            }
            //cout << s1 << endl;
        }
        if(isPalindrome){
            return s1;
        }else{
            s1 = s[0];
            return s1;
        }
        
    }
    bool judgePalindrome(string &s,int start,int end){
        bool flag = true;
        while(start < end){
            if(s[start] != s[end]){
                flag = false;
            }
            start++;
            end--;
        }

        return flag;
    }
};
```