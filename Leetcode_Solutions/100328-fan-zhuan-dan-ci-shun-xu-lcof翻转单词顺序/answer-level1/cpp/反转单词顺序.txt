### 解题思路
感觉是比较暴力的解法，实现思路分为以下5步：
1. 从头到尾找到第一个非空格字符串，并删除非空格字符串之前的所有空格（这里有个坑，需要判断能否找到第一个非空格字符，如果没找到，说明整个字符串都是空格组成，返回""即可）
2. 从尾到头找到最后一个非空格字符，并删除之后的空格即可
3. 删除两个单词之间的多余空格，遍历一遍字符串，如果当前字符是空格且上一个字符也是空格，那就将当前字符删除掉
4. 将整个句子反转
5. 将句子中的每个单词反转

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        int first=-1;
        
        for (int i=0;i<n;i++){
            if (s[i]!=' '){
                first=i;
                break;
            }
        }
        if (first==-1){
            return "";
        }
        s.erase(0,first);
        n = s.length();
        int last=n-1;
        for (int i=n-1;i>=0;i--){
            if (s[i]!=' '){
                last=i;
                break;
            }
        }
        s.erase(1+last,n-last);
        int i=1;
        while (i<s.length()){
            if (s[i]==' '&s[i-1]==' '){
                s.erase(i,1);
                
            }
            else{
                i++;
            }
        }
        n = s.length();
        reverseString(s,0,n);
        
        int pre=0;
        
        for (int i=0;i<n;i++){
            if (s[i] == ' '){
                reverseString(s,pre,i);
                pre=i+1;
            }
        }
        if (pre<n){
            reverseString(s,pre,n);
        }
        return s;
    }
    void reverseString(string& s,int l,int r){
        while (l<r){
            swap(s[l++],s[--r]);

        }
    }
};
```