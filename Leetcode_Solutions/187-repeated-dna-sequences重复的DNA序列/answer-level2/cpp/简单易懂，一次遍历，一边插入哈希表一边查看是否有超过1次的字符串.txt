class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string,int> hash;
        for(int i=0;i+9<s.size();i++)//保证从i起包括i有10个字符
        {
            string str=s.substr(i,10);
            hash[str]++;//如果没有str，那么插入str并且value为1（因为初始value为1？），如果有str，那么value+1。哈希表的这个特性非常好用，程序可以写的很简洁
            if(hash[str]==2) res.push_back(str);//为了只遍历一次，一边插入哈希表一边查看是否有出现超过1 次的，那么就需要判断是否等于2，如果写大于等于2，那么后面有大于2次的还会重复添加
        }
        return res;
    }
};