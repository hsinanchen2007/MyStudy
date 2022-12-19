 分割成字符串数组(分割过程中去掉前导0), 然后挨个比较.

不用整数数组的原因是防止大整数溢出.

    void split(vector<string>& res, const string& val) {
        int begin = 0;
        int pos = 0;
        while (pos < val.size()) {
            pos = val.find(".", begin);
            if (pos < 0) {
                pos = val.size();
            }
            string t = val.substr(begin, pos - begin);
            //去掉前导0
            int i = 0;
            for (i = 0; i < t.size(); i++) {
                if (t[i] != '0') {
                    break;
                }
            }
            if (i > 0) {
                t = t.substr(i, t.size() - i);
                if (t.empty()) {
                    t = "0";
                }
            }
            res.push_back(t);
            begin = pos + 1;
        }
    }
    int compareNum(const string& n1, const string& n2) {
        const int s1 = n1.size(), s2 = n2.size();
        if (s1 != s2) {
            //因为已经去掉了前导0, 所以长度不一样的话,  比较长的那个大. 直接返回就行
            return n1.size() > n2.size() ? 1 : -1;
        }
        for (int i = 0; i < s1; i++) {
            char c1 = n1[i], c2 = n2[i];
            if (c1 != c2) {
                return c1 > c2 ? 1 : -1;
            }
        }
        return 0;
    }

    int compareVersion(const string& version1, const string& version2) {
        vector<string> vlist1, vlist2;
        split(vlist1, version1);
        split(vlist2, version2);

        int size = min(vlist1.size(), vlist2.size());
        int i = 0;
        for (; i < size; i++) {
            string& v1 = vlist1[i], &v2 = vlist2[i];
            if (int res = compareNum(v1, v2); res != 0) {
                return res;
            }
        }
        while (i < vlist1.size()) {
            if (vlist1[i] != "0") {
                return 1;
            }
            i++;
        }
        while (i < vlist2.size()) {
            if (vlist2[i] != "0") {
                return -1;
            }
            i++;
        }
        return 0;
    }