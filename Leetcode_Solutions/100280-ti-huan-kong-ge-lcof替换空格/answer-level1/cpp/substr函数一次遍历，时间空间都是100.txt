### 解题思路
substr截取空格左右两边子串并且中间加上"%20"就行了
![image.png](https://pic.leetcode-cn.com/fbd717983d762b6df5444ca5c7f8f3daf6b8b114b0551ec49605e9e7ed07ce78-image.png)


### 代码

```cpp
class Solution {
public:
    string replaceSpace(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                s=s.substr(0,i)+"%20"+s.substr(i+1);
            }
        }
        return s;
    }
};
```