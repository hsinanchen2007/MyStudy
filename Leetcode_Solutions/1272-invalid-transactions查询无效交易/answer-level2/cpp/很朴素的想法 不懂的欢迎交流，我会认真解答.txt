利用istringstream来分割‘,’，将名称时间数额城市和总的字符串存放在结构体中，利用map来寻找名称一样的交易，在遍历的时候将数额超过1000的交易以及不同城市相同名称时间间隔过小的交易直接放入集合，不用担心是否会重复存放，因为一样的集合会自动过滤。最后遍历集合将交易转移到数组中输出。



```
class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
            set<string> res;
            vector<string> p;
            map<string,vector<stu>> ans;
            for(string s:transactions)
            {
                istringstream is(s);
                stu skr;
                getline(is,skr.name,',');
                getline(is,skr.time,',');
                getline(is,skr.money,',');
                getline(is,skr.city,',');
                skr.last = s;
                if(ans.find(skr.name)!=ans.end())
                {
                    for(int n = 0; n < ans[skr.name].size(); n++)
                    {
                        if(stoi(ans[skr.name][n].time) - stoi(skr.time) <=60&&stoi(ans[skr.name][n].time) - stoi(skr.time)>=-60&&ans[skr.name][n].city!=skr.city)
                        {
                            res.insert(skr.last);
                            res.insert(ans[skr.name][n].last);
                        }
                    }
                    ans[skr.name].push_back(skr);
                    if(stoi(skr.money)> 1000) res.insert(skr.last);
                }
                else
                {
                    ans[skr.name].push_back(skr);
                    if(stoi(skr.money)>1000) res.insert(skr.last);
                }
            }
            for(set<string>::iterator it = res.begin(); it != res.end(); it++)
            {
                p.push_back(*it);
            }
            return p;
    }
private:
    struct stu{
        string name;
        string time;
        string money;
        string city;
        string last;
    };
};
```
