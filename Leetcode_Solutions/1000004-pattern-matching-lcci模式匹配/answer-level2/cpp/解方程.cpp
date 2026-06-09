```

class Solution {
public:
    bool patternMatching(string pattern, string value)
    {
        int psize = pattern.length();
        int vsize = value.length();
        if (vsize == 0) {
            return psize < 2;  // a、b若存在，则是"", 但是a、b不能同时相同
        }

        if (psize == 0) {
            return false;
        }

        for (auto c : pattern) {
            pmap[c]++;
        }

        if (!(GetLen(vsize))) {
            return false;
        }
        return Check(pattern, value);
    }

private:
    struct Node {
        int aLen;
        int bLen;
        Node(int l1, int l2) : aLen(l1), bLen(l2)
        {
        }
        bool operator<(const Node &n) const
        {
            return aLen < n.aLen;
        }
    };

    bool GetLen(int vsize)
    {
        int aLen = 0;
        int bLen = 0;
        if ((pmap['a'] == 0) && (pmap['b'] == 0)) {
            return false;
        }

        if (pmap['a'] == 0) {
            if (vsize % pmap['b'] != 0) {
                return false;
            }
            bLen = vsize / pmap['b'];
            lset.insert(Node(0, bLen));
            return true;
        }

        if (pmap['b'] == 0) {
            if (vsize % pmap['a'] != 0) {
                return false;
            }
            aLen = vsize / pmap['a'];
            lset.insert(Node(aLen, 0));
            return true;
        }

        for (int aLen = 0; aLen < vsize + 1; aLen++) {  // aLen * count('a') + aLen * count('b') = vsize;
                                                        // aLen长度最大为vsize
            int lev = vsize - aLen * pmap['a'];
            if ((lev < 0) || (lev % pmap['b'] != 0)) {
                continue;
            }

            int bLen = lev / pmap['b'];
            lset.insert(Node(aLen, bLen));
        }

        return lset.size() != 0;
    }

    bool CheckItem(string value, int len, string &str, int idx)
    {
        if (idx + len > value.size()) {
            return false;
        }

        if ((str == "A") || (str == "B")) {
            str = value.substr(idx, len);
            idx += len;
            return true;
        }

        for (int i = 0; i < len; i++) {
            if (value[idx + i] != str[i]) {
                return false;
            }
        }

        return true;
    }

    bool CheckOne(string pattern, string value, Node &node)
    {
        int psize = pattern.length();
        int vsize = value.length();
        int idx = 0;
        string stra = "A";
        string strb = "B";
        while (idx < vsize) {
            for (auto c : pattern) {
                if (c == 'a') {
                    if (!CheckItem(value, node.aLen, stra, idx)) {
                        return false;
                    }
                    idx += node.aLen;
                } else if (c == 'b') {
                    if (!CheckItem(value, node.bLen, strb, idx)) {
                        return false;
                    }
                    idx += node.bLen;
                }
            }
        }

        return idx == vsize;
    }

    bool Check(string pattern, string value)
    {
        int psize = pattern.length();
        int vsize = value.length();

        for (auto ls : lset) {
            if (CheckOne(pattern, value, ls)) {
                return true;
            }
        }
        return false;
    }

    map<char, int> pmap;
    set<Node> lset;
};
```
