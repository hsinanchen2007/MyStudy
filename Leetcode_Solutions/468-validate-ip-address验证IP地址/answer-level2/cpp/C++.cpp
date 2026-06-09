class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.size()<=1)
            return "Neither";
        if(IP[0]=='.'||IP[0]==':')
            return "Neither";
        vector<string> v;
        if(IP.find(':')!=IP.npos){
            if(isIPv6(IP))
                return "IPv6";
        }
        else if(IP.find('.')!=IP.npos){
            string temp="";
            for(int i=0;i<IP.size();++i){
                if(IP[i]!='.'&&!(IP[i]>='0'&&IP[i]<='9'))
                    return "Neither";
                else if(IP[i]!='.')
                    temp+=IP[i];
                else{
                    if(temp=="")return "Neither";
                    v.push_back(temp);
                    temp="";
                }
                if(i==IP.size()-1){
                    if(temp=="")return "Neither";
                    v.push_back(temp);
                }
            }
   
            if(v.size()!=4)
                return "Neither";
            for(int i=0;i<4;++i){
                if(v[i][0]=='0'&&v[i].size()!=1)
                    return "Neither";
                if(atoi(v[i].c_str())<0||atoi(v[i].c_str())>255)
                    return "Neither";
            }
            return "IPv4";
        }
        return "Neither";
    }
    
    bool isIPv6(string s){
        vector<string> v;
        string temp="";
        for(int i=0;i<s.size();++i){
            if(s[i]!=':'&&!(s[i]>='0'&&s[i]<='9')&&!(s[i]>='a'&&s[i]<='f')&&!(s[i]>='A'&&s[i]<='F'))
                return false;
            if(s[i]!=':')
                temp+=s[i];
            else{
                v.push_back(temp);
                if(temp=="")return false;
                temp="";
            }
            if(i==s.size()-1){
                if(temp=="")return false;
                v.push_back(temp);
            }
        }
        if(v.size()!=8)
            return false;
        for(int i=0;i<8;++i){
            if(v[i].size()>4||v[i].size()==0)
                return false;
        }
        return true;
    }
};