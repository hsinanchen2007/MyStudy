### 解题思路
做牛ke网面试题的时候，很有用；先getline一行，每行在如本题，放入stringstream

### 代码1

```cpp
class Solution {
public:
    string reverseWords(string s) {
        vector<string> cache;
        stringstream str(s);
        string temp;
        while(getline(str,temp,' ')){
            if(temp !=""){
                cache.push_back(temp);
            }
            
        }
        string res;
        for(int i=cache.size()-1;i>=0;i--){
            res += cache[i];
            if(i!=0) res += ' ';
        }
        return res;
    }
};
```

### 双指针法
```
class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.size() - 1;
        // 去掉字符串头尾的空白字符
        while (left <= right && s[left] == ' ') ++left;
        while (left <= right && s[right] == ' ') --right;
        s = s.substr(left,right-left+1);

        int j = s.size()-1,i=s.size()-1;
        string res;
        while(i>=0){
            while(i>=0 && s[i]!=' ') i--; // 搜索单词到空格为止
            res += s.substr(i+1,j-i)+' ';  // 添加单词
            while(i>=0 && s[i]==' ') i--; // 跳过单词间空格
            j=i; // j 指向下个单词的尾字符
        }
        
        return res.substr(0,res.size()-1);
    }
};
```
