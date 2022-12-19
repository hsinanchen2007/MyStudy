### 解题思路
        将字符串作为输入流进行读取，每个单词插入数组，在反向拼接起来就完事了

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        istringstream sin(s);  //输入流
        string temp;
        vector<string>a;

        while(sin >> temp){ //读取每个单词放入数组
            a.push_back(temp);
        }

        if(a.size()==0) return "";  //没单词返回空字符

        temp="";
        for(int i=a.size()-1;i>0;--i){ //反向拼接完成
            temp+=a[i]+" ";
        }
        temp+=a[0];
        return temp;
    }
};
```