方法一、reverse函数
```
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
    }
};
```
![image.png](https://pic.leetcode-cn.com/8b6bb2f84a9fac1f7e328560d4d2780f3926cf33c1d9b001b8f87928664ef724-image.png)

方法二首尾索引(双指针)
```
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0, j=s.size()-1;
        char tmp;
        while(i<j){
            tmp= s[i];
            s[i]= s[j];
            s[j]=tmp;
            i++;
            j--;
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/b5b4c4c6337a574ba4072f131c0788f4cf6256f18c06837054257b45db40e46c-image.png)
