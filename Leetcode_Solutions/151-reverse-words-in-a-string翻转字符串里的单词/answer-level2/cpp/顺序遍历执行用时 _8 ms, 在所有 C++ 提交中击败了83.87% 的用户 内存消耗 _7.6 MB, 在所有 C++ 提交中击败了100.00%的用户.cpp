### 解题思路
此处撰写解题思路

### 代码

```cpp
//简单方法
class Solution {
public:
    string reverseWords(string s) {
        if(s.empty()) return "";
        //先反转
        reverse(s.begin(),s.end());
        //去除前后空格
        int start = 0 , end = s.size() - 1;
        while(s[start] == ' ' && start < s.size()) start++;
        while(s[end] == ' ' && end > 0) end--;
        if(start > end) return "";

        //对单词进行反转(两个指针-快慢指针，确定需要反转的单词)
        for(int right = start, left = start ; right <= end ;)
        {
            while(s[right] != ' ' && right <= end) right++;
            reverse(s.begin()+left , s.begin()+right);
            //reverse(&s[left],&s[right]);
            left = right;
            while(s[left] == ' ' && left <= end) left++;
            right = left;
        }

        //去掉单词间的多余空格
        int new_index = start;;
        for(int i = start ; i <= end ; i++)
        {
           if(s[i] == ' ' && s[i-1] == ' ') continue; 
           s[new_index] = s[i];
           new_index++;
        }
        return s.substr(start,new_index - start);
        
    }
};
```