```
class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string>strs; // 存放单个子串
        vector<string>res;  // 存放返回结果
        string str = "";    // 初始化单个子串的值
        int len = s.size(); // 字符串的长度
        int maxlen = 0;     // 记录最长的子串的长度
        int cnt = 0;        // 记录子串的个数

        // 确定第一个字母的位置
        int index = 0;
        while(isspace(s[index])){
            index++;
        }

        // 提取单独的字符串到strs
        for(int i = index; i < len; i++){
            if(isspace(s[i])){
                strs.push_back(str);
                cnt++;
                if(str.length() > maxlen){
                    maxlen = str.length();
                }
                str = "";
                while(s[i + 1] == ' '){
                    i++;
                }
                continue;
            }
            str += s[i];
        }
        if(str.length() > maxlen){
            maxlen = str.length();
        }
        strs.push_back(str);
        cnt++;
        str = "";

        // 对strs进行处理
        for(int i = 0; i < maxlen; i++){
            // 这个for循环的作用是提取单个的子串到str
            for(int j = 0; j < cnt; j++){
                if(i >= strs[j].size()){
                    str += ' ';
                }else{
                    str += strs[j][i];
                }
            }
            
            int size = str.size() - 1;
            // 判断str是否以空格结尾
            // 如果是，将空格删除直到遇到字符就结束
            if(isspace(str[size])){
                while(isspace(str[size])){
                    size--;
                }
                string strtemp = "";
                for(int k = 0; k <= size; k++){
                    strtemp += str[k];
                }
                res.push_back(strtemp);
                str = "";
            }else{ // 否则直接添加到res中
                res.push_back(str);
                str = "";
            }
        }
        return res;
    }
};
```
![1.png](https://pic.leetcode-cn.com/a79a4b8f7ea5246770cef9163b11f1f746140504cf32daef798ea0a3aa58158f-1.png)
