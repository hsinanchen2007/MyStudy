![360截图20200405152420808.jpg](https://pic.leetcode-cn.com/338d2641d2e53579725caec437166644893c49820c555caeb6f733c250c13180-360%E6%88%AA%E5%9B%BE20200405152420808.jpg)

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
         unordered_map<string, int> a;
        vector<string> res;
        int a_len = A.length();
        int b_len = B.length();
        int i = 0, j = 0;
        while (j < a_len && i <= j) {
            while (A[j] != ' ' && j < a_len) j++;
            //j--;
            string temp = A.substr(i, j - i);
            a[temp]++;
            j += 1;
            i = j;
        }
        i = j = 0;
        while (j < b_len && i <= j) {
            while (B[j] != ' ' && j < b_len) j++;
            //j--;
            string temp = B.substr(i, j - i);
            a[temp]++;
            j += 1;
            i = j;
        }
        unordered_map<string, int>::iterator itr;
        for (itr = a.begin(); itr != a.end(); itr++) {
            if (itr->second < 2) res.push_back(itr->first);
        }
       return res;
        
    }
};