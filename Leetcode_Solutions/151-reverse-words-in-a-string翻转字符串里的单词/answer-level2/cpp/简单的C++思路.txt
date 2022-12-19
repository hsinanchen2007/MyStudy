### 解题思路

最简单的方法就是用一个数组存储每个单词，其中取单词是每到达空格算是一个单词的结尾，而下一个不是空格的字符是新单词的开始。

然后再倒序取出来数组中的单词拼接在一起，时间复杂度和空间复杂度都为O(n)

### 代码

```cpp

class Solution {
public:
  string reverseWords(string s) {
​    vector<string> strs;
​    string ans = "";
​    string sub = "";
​    for(int i = 0; i < s.size(); i ++){
​      //到达空格
​      if(s[i] == ' '){
​        //到达单词末尾
​        if(sub.size() > 0){
​          strs.push_back(sub);
​          sub = "";
​        }
​      } else{
​        sub += s[i];
​        if(i == s.size() - 1) strs.push_back(sub);
​      }
​    }
​    for(int i = strs.size() - 1; i >= 0; i --){
​      ans += strs[i];
​      if(i != 0) ans += " ";
​    }
​    return ans;
  }
};

```

>我看到官网有使用双端队列，其实就是利用双端队列的性质，每次把单词查到队头，最后再依次从队头取出单词连接在一起，如果把dequeue换成stack当然也是可以的

```cpp

class Solution { 
public:    
    string reverseWords(string s) {        
        int left = 0, right = s.size() - 1;        
        // 去掉字符串开头的空白字符        
        while (left <= right && s[left] == ' ') ++ left;        
        // 去掉字符串末尾的空白字符        
        while (left <= right && s[right] == ' ') -- right;         
        deque<string> d;        
        string word;         
        while (left <= right) {            
            char c = s[left];            
            if (word.size() && c == ' ') {               
                // 将单词 push 到队列的头部                
                d.push_front(move(word));                
                word = "";            
            } else if (c != ' ') {               
                word += c;            
            }           
            ++left;       
        }        
        d.push_front(move(word));     
        string ans;        
        while (!d.empty()) {            
            ans += d.front();            
            d.pop_front();            
            if (!d.empty()) ans += ' ';       
        }        
        return ans;    
    } 
};

```

>如果是倒着遍历的话就不需要额外使用数组了

```cpp

class Solution {
public:
  string reverseWords(string s) {
​    if(s.size() == 0) return "";
​    string ans = "";
​    string sub = "";
​    int n = s.size();
​    for(int i = n - 1; i >= 0; i --){
​      if(s[i] == ' '){
​        //到达一个单词的开头
​        if(sub.size() > 0){
​          ans += sub + " ";
​          sub = "";
​        }
​      } else{
​        sub = s[i] + sub;
​        if(i == 0) ans += sub;
​      }
​    }
​    if(ans.size() > 0 && ans[ans.size() - 1] == ' ') 
​      ans.pop_back();
​    return ans;
  }
};

```

![image.png](https://pic.leetcode-cn.com/61fd97e091a8288c338633aa20ddd4cd503056d96e2f0dad9bcb3fa1b0cca8d2-image.png)
