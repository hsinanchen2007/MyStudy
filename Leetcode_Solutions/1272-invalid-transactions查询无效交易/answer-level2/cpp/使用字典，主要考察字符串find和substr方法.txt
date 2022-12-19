class Solution {
public:
    struct Trans{
        int time;
        int amount;
        string city;
        string alls;
        bool invalid;
        Trans(int t, int a, string c, string s) : time(t), amount(a), city(c), alls(s)
        {
            invalid = false;
            if (amount > 1000) {
                invalid = true;
            }
        }
    };

    void GetItem(string s)
    {
        int nameEndIndex = s.find(',');
        string name = s.substr(0, nameEndIndex);
        
        int timeEndIndex = s.find(',', nameEndIndex + 1);
        int time = stol(s.substr(nameEndIndex + 1, timeEndIndex));

        int amountEndIndex = s.find(',', timeEndIndex + 1);
        int amount = stol(s.substr(timeEndIndex + 1, amountEndIndex));

        string city = s.substr(amountEndIndex + 1);
        Trans item(time, amount, city, s);
        mapItem[name].push_back(item);
        // cout << "name = " << name << " time = " << time << " amount = " << amount << " city = " << city << endl;
    }

    void Update(vector<Trans> &trans)
    {
        int size = trans.size();
        for (int i = 0; i < size - 1; i++) {
            string city1 = trans[i].city;
            int time1 = trans[i].time;
            for (int j = i + 1; j < size; j++) {
                string city2 = trans[j].city;
                if (city1 == city2) {
                    continue;
                }

                int time2 = trans[j].time;
                if (abs(time1 - time2) > 60) {
                    continue;
                }

                trans[i].invalid = true;
                trans[j].invalid = true;
            }
        }
    }

    void CalcProc()
    {
        for (auto &item : mapItem) {
            vector<Trans> &trans = item.second;
            Update(trans);
        }
    }

    void GetResult(vector<string> &res)
    {
        for (auto &item : mapItem) {
            vector<Trans> trans = item.second;
            for (auto &transItem : trans) {
                if (transItem.invalid) {
                    res.push_back(transItem.alls);
                }
            }
        }
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        int size = transactions.size();
        for (int i = 0; i < size; i++) {
            GetItem(transactions[i]);
        }

        CalcProc();
        GetResult(res);
        return res;
    }
private:
    map<string, vector<Trans> > mapItem;    
};