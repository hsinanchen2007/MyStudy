```
class Solution {
public:
    string replaceSpace(string s) {
        int len = s.length();
        int m = 0;
        char a[10000] = "\0";  //创建一个空字符串数组
        for(int i = 0; i < len; i ++){
            if(s[i] == ' '){
                a[i + 2 * m] = '%';
                a[i + 2 * m + 1] = '2';
                a[i + 2 * m + 2] = '0';
                m ++;
            }  
            else{
                a[i + 2 * m] = s[i];
            }
        }
        return a;
    }
};
```
![图片.png](https://pic.leetcode-cn.com/9fbc60f51a925e9d811671de9f0e6dcb66a2ee7a9c4a43bf703ccca0b00e7cb2-%E5%9B%BE%E7%89%87.png)
