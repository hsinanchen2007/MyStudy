```
class Solution {
public:
    int time2int(const string& time) {
        int res = 0;
        for (int i = 0; i < time.size(); ++i) {
            if (time[i] == ':')
                continue;
            res += res * 10 + time[i] - '0';
        }
        return res;
    }
    string nextClosestTime(string time) {
        set<int> nums;
        for (int i = 0; i < 5; ++i) {
            if (time[i] == ':')
                continue;
            nums.insert(time[i] - '0');
        }
        const int MAX_TIME = time2int("23:59");
        int ori = time2int(time);
        int min_num = *nums.begin();
        for (int i = 4; i >= 0; --i) {
            if (time[i] == ':')
                continue;
            auto it = nums.upper_bound(time[i] - '0');
            if (it != nums.end()) {
                time[i] = *it + '0';
                int t = time2int(time);
                if (t > ori && t < MAX_TIME && time[3] < '6') {
                    return time;
                }
            }
            time[i] = min_num + '0';
        }
        char res[6] = "";
        sprintf(res, "%d%d:%d%d", min_num, min_num, min_num, min_num);
        return string(res);
    }
};
```
