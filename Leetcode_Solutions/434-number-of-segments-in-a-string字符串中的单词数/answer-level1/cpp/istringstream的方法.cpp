第一次写题解。之前看到过istringstream，觉得用来对付这个题正好呀。把s放到输入流里就可以读出单词了，每次读出的时候，count++。
class Solution {
public:
    int countSegments(string s) {
        istringstream ss(s);
        string str;
        int count=0;
        while (ss >> str) count++;
        return count;
    }
};