用@分割本地和域名，按规则简化本地，与域名和@拼接在一起插入集合，最终返回集合大小（自动去重）

代码：
```
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> mail;
        int size = emails.size();
        for (int i = 0; i < size; i++) {
            string name = emails[i];
            int len = name.length();
            int position = name.find("@");
            string local = name.substr(0, position);
            string domain = name.substr(position + 1, len - 1 - position);
            for (string::iterator it = local.begin(); it != local.end(); it++) {
                if (*it == '.') {
                    local.erase(it);
                    it--;
                }
            }
            int pos = local.find("+");
            local = local.substr(0, pos);
            mail.insert(local + "@" + domain);
        }
        return mail.size();
    }
};
```
