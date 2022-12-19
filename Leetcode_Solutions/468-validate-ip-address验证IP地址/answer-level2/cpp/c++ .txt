这个测试用例没过。但按照题目描述，不应该是"Neither"吗？这个地址有“0000”啊。
输入：
"2001:0db8:85a3:0000:0:8A2E:0370:733a"
输出：
"Neither"
预期：
"IPv6"
```
class Solution {
public:
    string validIPAddress(string IP) {
        if((IP[IP.size()-1]==':')||(IP[IP.size()-1]=='.'))return "Neither";
        auto ips=split(IP);
        if(ips.size()==4){
            for(auto &ip:ips){
                if(ip=="0")continue;
                int num=0;
                for(auto c:ip){
                    if(c>='0'&&c<='9')num=num*10+c-'0';
                    else return "Neither";
                }
                if(num>255||num==0)return "Neither";
            }
            return "IPv4";
        }
        if(ips.size()==8){
            for(auto &ip:ips){
                if(ip=="0")continue;
                int num=0;
                for(auto c:ip){
                    if(c>='0'&&c<='9')num=num*16+c-'0';
                    else if(c>='a'&&c<='f')num=num*16+c-'a';
                    else if(c>='A'&&c<='F')num=num*16+c-'A';
                    else return "Neither";
                }
                if(num>65535||num==0)return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }
    vector<string> split(string &IP){
        vector<string> res;
        int start=0;
        while(start<IP.size()){
            int end=start;
            while(end<IP.size()&&!(IP[end]=='.'||IP[end]==':'))++end;
            res.push_back(IP.substr(start,end-start));
            if(end>=IP.size())break;
            start=end+1;
        }
        return res;
    }
};
```
