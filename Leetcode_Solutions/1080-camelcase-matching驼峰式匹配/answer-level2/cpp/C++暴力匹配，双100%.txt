![image.png](https://pic.leetcode-cn.com/3a7dad3007d41cfc34e44f0f7579d615091b9f6ae110d6acda5acfecfc373d56-image.png)

对每个query，分别与pattern进行匹配，两个指针分别指向两个字符串的开始，遍历query的指针，如果当前字符与pattern指针指向的字符相同，就把pattern指针向后移动一格，如果中间遇到不匹配的小写字符就跳过，如果遇到不匹配的大写字符直接返回不匹配，最后判断pattern指针是否指向最后

```
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for(string q:queries){
            ans.push_back(check(q, pattern));
        }
        return ans;
    }

    bool check(string q, string p){
        if(q.length()<p.length())
            return false;
        int count = 0;
        for(int i=0; i<q.length(); i++){
            if(q[i]==p[count]){
                count++;
                continue;
            }
            if('a'<=q[i]&&q[i]<='z'){
                continue;
            }else{
                return false;
            }
        }
        return count==p.length();
    }
};
```
