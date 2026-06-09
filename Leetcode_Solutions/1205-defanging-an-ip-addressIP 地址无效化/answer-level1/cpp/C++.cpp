class Solution {
public:
    string defangIPaddr(string address) {
        string nIP = "[.]";
        string addr;
        int i = 0;
        for(int i = 0; i < address.size(); i++){
            if(address[i] == '.'){
                addr = addr + nIP;
            }
            else
                addr = addr + address[i];
        }
        return addr;
    }
};