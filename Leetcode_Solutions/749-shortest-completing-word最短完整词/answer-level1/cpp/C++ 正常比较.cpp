![360截图20200403150718720.jpg](https://pic.leetcode-cn.com/9b3c8a9c8e90cb226faaee02f1a4fe1a13a9e859ee97a347c3c1f9d2444b9c93-360%E6%88%AA%E5%9B%BE20200403150718720.jpg)

class Solution {
public:

int func(string s, string t) {
    //func(wordss[i], licensePlate)
    int n1 = s.length();
    int n2 = t.length();
    int i = 0, j = 0;
    if (s.length() == 0 && t.length() == 0) return 1;
    if (s.length() == 0 || t.length() == 0) return 0;
    while (i < n1 && j < n2) {
        if (s[i] == t[j]) { i++; j++; }
        else if (s[i] < t[j]) { i++; }
        else return 0;
    }
    if (j == n2) return 1;
    else return 0;
}


    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string licensePlates;
        string res;
        int min_len = 1000;
        //sort(licensePlate.begin(), licensePlate .end());
        for(int i = 0;i<licensePlate.length();i++) {
            if(licensePlate[i] >='A' && licensePlate[i] <='Z')
                licensePlates += licensePlate[i] +32;
            if(licensePlate[i] >='a' && licensePlate[i] <='z')
                licensePlates += licensePlate[i];
        }
        sort(licensePlates.begin(), licensePlates.end());// licensePlates=s
        vector<string> wordss(words);//wordss={"looks", "pest", "stew", "show"}
        for(int i = 0;i<wordss.size();i++) {
            sort(wordss[i].begin(),wordss[i].end());
        }
        //wordss={"kloos", "epst", "estw", "hosw"}
        for(int i = 0;i<wordss.size();i++) {
            //if(wordss[i].find(licensePlates) != string::npos) {
            if (func(wordss[i],licensePlates) == 1) {
                if(wordss[i].length() < min_len) {
                    min_len=wordss[i].length();
                    res = words[i];
                }
               
            }
        }
        return res;


    }
};