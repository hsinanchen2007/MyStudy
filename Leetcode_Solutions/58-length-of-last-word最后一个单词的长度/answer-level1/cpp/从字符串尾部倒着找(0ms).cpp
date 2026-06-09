从字符串尾部倒着找，找到第一个不为空格的位置，从这个位置开始数
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int lastlen=0,first=0,index=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                first=1;
                index=i;
                break;
            } 
        }
        if(first){
            for(int i=index;i>=0;i--){
                if(s[i]!=' ') lastlen++;
                else break;
            }
        }
        return lastlen;
    }
};
```
![image.png](https://pic.leetcode-cn.com/998f707b2c2b117ecb5c66e82238ec5f2c2171ef35ade3621548e1fb99b37dea-image.png)

