注意，可以重复利用。如子串[0,9]和子串[1,10]，可以重复利用每个字节。
遍历一遍，每十个字节作为子串，统计其出现次数。最终将出现超过一次的子串插入数组返回。
```
// Method 1, Time 64ms 81%, Space 24.4MB 17.5%
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> vs;
        unordered_map<string,int> freqs;
        for(int i=0; i+10<=s.length(); freqs[s.substr(i++,10)]++);
        for(const auto &p:freqs)
            if(p.second>1) vs.push_back(p.first);
        return vs;
    }
};
```
可以进一步优化空间。DNA序列有且仅有ACGT四种字节，可以映射为0,1,2,3.正好2bit，十个字节就是20bit，可以使用32bit int存储。
```
// Method 2, Time 56ms, 87%, Space 16.6MB 85%
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10) return {};
        unordered_map<char,int> dict={{'A',0},{'C',1},{'G',2},{'T',3}};
        int key=0, K=(1<<20)-1;
        for(int i=0; i<9; key=(key<<2)|dict[s[i++]]);
        vector<string> vs;
        unordered_map<int,int> freqs;
        for(int i=9; i<s.length(); ++i){
            key = K & (key<<2) | dict[s[i]];
            ++freqs[key];
            if(freqs[key]==2) vs.push_back(s.substr(i-9,10));
        }
        return vs;
    }
};
```
