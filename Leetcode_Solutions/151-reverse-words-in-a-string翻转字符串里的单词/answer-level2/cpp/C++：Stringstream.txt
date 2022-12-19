##### 在c++中，cin一个字符串是可以自动跳过空白符的
##### 所以如果将字符串重新变回输入流，再使用cin依次读取
##### 那么就能达到去除空格的目的

```cpp
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;      //创建字符串流
        ss<<s;                //将s读入流中
        vector<string> data;  //存储
        string ans = "",t;
        while(ss>>t) data.push_back(t);  //重新从流中读取字符串
        if(data.size() == 0) return "";
        for(int i = data.size()-1;i > 0;i--) ans += data[i]+" ";
        ans += data[0];
        return ans;
    }
};
```
