### 解题思路
做道题我容易吗
### 代码

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int index_1{-1};
        int index_2{-1};
        for(int i=0;i<emails.size();++i) {
            index_1 = -1;
            index_2 = -1;
            for(int j=0;j<emails[i].size();++j) {
                if(emails[i][j] == '+') {
                    index_1 = j;
                    break;
                }
            }
            for(int j=0;j<emails[i].size();++j) {
                if(emails[i][j] == '@') {
                    index_2 = j;
                    break;
                }
            }
            //std::cout<<emails[0]<<"    "<<emails[1]<<"      "<<emails[2]<<std::endl;
            if(index_1 != -1 && index_2 != -1) emails[i].erase(index_1, index_2-index_1);
        }
        //std::cout<<emails[0]<<"    "<<emails[1]<<"      "<<emails[2]<<std::endl;
        for(int i=0;i<emails.size();++i) {
            for(int j=0;j<emails[i].size();++j) {
                if(emails[i][j] != '@') {
                    if(emails[i][j] == '.') emails[i].erase(j, 1);
                }
                else break;
            }
        }
        //std::cout<<emails[0]<<"    "<<emails[1]<<"      "<<emails[2];
        sort(emails.begin(), emails.end());
        emails.erase(unique(emails.begin(), emails.end()), emails.end());
        return emails.size();
    }
};
```