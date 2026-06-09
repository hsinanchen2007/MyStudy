```
class Solution {
    vector<int> mp;
    bool yeapyear(int year)
    {
        return year %400 == 0 || (year%100!= 0 && year %4 == 0);
    }
    int days(string date1)
    {
        istringstream s1(date1 + '-');
        char dot = '-';
        int val1;
        vector<int> v;
        while(s1.good())
        {
            s1 >> val1 >> dot;
            v.push_back(val1);
        }
        int res = 0;
        for(int i = 0; i < v[0]; i++)
        {
            res += yeapyear(i)? 366:365;
        }


        for(int i = 1; i < v[1]; i++)
        {
            res += mp[i];
            if(i == 2 && yeapyear(v[0])) res += 1;
        }


        res += v[2];
        return res;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        mp = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(date1 > date2) swap(date1, date2);
        return days(date2) - days(date1);
    }
};
```
