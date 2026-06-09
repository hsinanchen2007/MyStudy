备注写的挺详细
如有疏漏，请指正
这道题就是很多边边角角需要考虑，也是提交了好几次，修修补补才通过的
过程中突然想到可用用stringstream + while 的方法来分割字符串，对于这道ip地址的题目特别好用，可以省很多代码
```
class Solution {
public:
    string validIPAddress(string IP) {
        string str;
	    stringstream ss,ss1;
		ss << IP;
	    int count4=4,count6=8; //保证组数不多不少
        if(IP.find('.')!=-1 && IP.find(':')!=-1) return "Neither";  //连个分隔符都没有，一定不对
    	else if(IP.find('.')!=-1){
            if(IP[IP.size()-1]=='.') return "Neither";//不能以.结尾
            int n_ipv4;
	    	while(getline(ss,str,'.')){  //..时能分割出一个空串
		    	count4--;
                for(int k=0; k!=str.size(); k++) 
                if(str[k]<'0' || str[k]>'9') return "Neither"; //ipv4内容必须全部是数字字符 
                ss1 << str;
		    	ss1 >> n_ipv4;
		    	ss1.clear(); //string转换为int 
		    	if(str=="") return "Neither"; //不能出现192..2.255 
			    else if(str.size()>1 && str[0]=='0') return "Neither";  //不能多余零
			    else if(n_ipv4>=0&&n_ipv4<=255) continue;  //不能出现192.0.0.666
			    else return "Neither";
            }
            if (count4==0) return "IPv4";  //必须是4组才行
            else return "Neither";
	    }
	    else{
            if(IP[IP.size()-1]==':') return "Neither";
            int n_ipv6;
		    while(getline(ss,str,':')){
		    	count6--;
			    for(int k=0; k!=str.size(); k++) 
                    if(!((tolower(str[k])>='a'&& tolower(str[k])<='f') || (tolower(str[k])>='0'&& tolower(str[k])<='9'))) return "Neither";
                    //ipv6内容必须全部是数字字符或者是a-f的字母字符 
                if(str=="") return "Neither";   
		    	else if(str.size()>=5) return "Neither"; //不能出现出现 02123：......
		    }
            if (count6==0) return "IPv6";
            else return "Neither";
	    }
    }
};
```
