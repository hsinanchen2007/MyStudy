
失败多次的难点在于第一：程序只是在分割有效的IP地址，不需要转换为整型。第二：注意 00、01、005,等这类反人类的数字不属于正常的分割。不能把前面的字符串转为为int 后的值 0、1、5。这个是不对的。

static void bt_restoreip(string s, vector<string>&res, int index,vector<string> ipaddress) {
        if (index == s.length() && (ipaddress.size() == 4)){
            string strIP;

            for (int i = 0; i < ipaddress.size();i++)
            {
                strIP.append(ipaddress[i]);
                if (i != 3) {
                    strIP.append(".");
                }
            }

            res.push_back(strIP);
            return;
        }

        if (ipaddress.size() >= 4){
            return;
        }

        for (int i = 1; i <= 3;i++) {
            if (index + i > s.length()){
                break;
            }

            int ip = atoi(s.substr(index, i).c_str());
            if (ip > 255 || ip < 0){
                break;
            }
            
            if (to_string(ip) != s.substr(index, i)){
                break;
            }
            
            ipaddress.push_back(s.substr(index, i));
            bt_restoreip(s, res, index + i, ipaddress);
            ipaddress.pop_back();
        }

        return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int index = 0;
        vector<string> ipaddress;

        if (s.length() == 0){
            return res;
        }

        bt_restoreip(s, res, index,ipaddress);
        return res;
    }