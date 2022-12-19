定义迭代器
循环处理前n个字符，用临时变量记录当前首字符的ASCII码，然后删除首字符，此时it所指向地址不变，而第二个字符变成了首字符并存储在it指向的s.begin() 
然后将刚删除的字符放到s的最末位即可

需要注意的是，务必先删除前端字符再添加末端字符，否则有越界风险

```
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string::iterator it = s.begin();
        for(int i = 0; i < n; i++){
            int temp = *it;
            s.erase(it);
            s.push_back(temp);
        }
        return s;
    }
};
```
