```
class Solution {
public:
//执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
//内存消耗 :8.6 MB, 在所有 C++ 提交中击败了80.95%的用户
    int n;
    stringstream ss;
    string validIPAddress(string IP) {
        if(IP.find('.')!=-1) return judge1(IP);//判断是否为有效的IPv4地址
        else if(IP.find(':')!=-1) return judge2(IP);//判断是否为有效的IPv6地址
        else return "Neither";
    }
    string judge1(string ip) {
        int cnt,len;
        cnt = 0;len = ip.length();
        for(auto&it:ip) {
            if(it=='.') cnt++;//对分隔符计数
            else if(!(it>='0'&&it<='9')) return "Neither";//找到非法字符
        }
        if(cnt!=3||ip[0]=='.'||ip[len-1]=='.') return "Neither";//分隔符的基本非法情况
        auto v = trans(ip,'.');
        if(v.size()!=4) return "Neither";//根据分割符找到的元素数量是否正确
        for(auto&it:v) {
            if(it.length()>1&&it[0]=='0') return "Neither";//对0开头的元素进行分析
            ss.clear();ss << it;ss >> n;
            if(n>255) return "Neither";//判断数的范围
        }
        return "IPv4";
    }
    string judge2(string ip) {
        int cnt,len;
        cnt = 0;len = ip.length();
        for(auto&it:ip) {
            if(it==':') cnt++;
            else if(!(it>='0'&&it<='9'||it>='a'&&it<='f'||it>='A'&&it<='F')) return "Neither";
        }
        if(cnt!=7||ip[0]==':'||ip[len-1]==':') return "Neither";
        auto v = trans(ip,':');
        if(v.size()!=8) return "Neither";
        for(auto&it:v) if(it.length()>4) return "Neither";//判断每组的长度是否超过最大值
        return "IPv6";
    }
    vector<string> trans(string ip,char sep) { //根据分隔符提取元素
        vector<string> res;
        ip.push_back(sep);
        string tmp;
        for(auto&it:ip) {
            if(it==sep) {
                if(tmp!="") {
                    res.push_back(tmp);
                    tmp="";
                }
            }else tmp.push_back(it);
        }
        return res;
    }
};
```
