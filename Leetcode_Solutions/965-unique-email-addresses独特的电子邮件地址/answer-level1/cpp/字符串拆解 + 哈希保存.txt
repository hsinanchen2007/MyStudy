### 解题思路
参考y总的代码：
1、先找到电子邮件中字符'@'的位置，将email字符串分成两段;
2、对前一段进行'+'和'.'字符判断和字符拼接，得到name;
3、后一段直接使用substr截取得到域名domain;
4、插入name + '@' + domain 组成的字符串到hash中去;
5、最后返回hash的大小。
### 代码

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hash;//这里不要用unordered_map
        for(auto email : emails){
            string name;
            int index = email.find('@');
            for(auto c : email.substr(0,index)){
                if(c == '+') break;
                else if(c != '.') name += c;
            }
            string domain = email.substr(index + 1);
            hash.insert(name + '@' + domain);
        }
        return hash.size();
    }
};
```