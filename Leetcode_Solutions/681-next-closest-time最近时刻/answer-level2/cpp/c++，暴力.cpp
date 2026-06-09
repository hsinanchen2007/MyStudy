总共就256种情况，暴力即可
```
class Solution {
public:
    string nextClosestTime(string time) {
        string res;
        int minDiff = 100000;
        int num = strToInt(time);
        int nums[time.length()];
        for (int i = 0; i < time.length(); ++i) {
            nums[i] = time[i] - 48;
        }
        nums[2] = nums[3];
        nums[3] = nums[4];
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                int hour = nums[i] * 10 + nums[j];
                if (hour >= 24) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    for (int l = 0; l < 4; ++l) {
                        int minute = nums[k] * 10 + nums[l];
                        if (minute >= 60) {
                            continue;
                        }
                        int diff = getDiff(num, hour * 60 + minute);
                        if (diff < minDiff) {
                            minDiff = diff;
                            stringstream ss;
                            ss << nums[i] << nums[j] << ":" << nums[k] << nums[l];
                            res = ss.str();
                        }
                    }
                }
            }
        }
        return res;
    }

    int strToInt(const string &time) {
        return ((time[0] - 48) * 10 + time[1] - 48) * 60 + (time[3] - 48) * 10 + time[4] - 48;
    }

    int getDiff(int time1, int time2) {
        if (time2 <= time1) {
            time2 += 24 * 60;
        }
        return time2 - time1;
    }
};
```