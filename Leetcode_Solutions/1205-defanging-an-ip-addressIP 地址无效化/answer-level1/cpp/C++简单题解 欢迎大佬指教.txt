class Solution {
public:
    string defangIPaddr(string address) {
        string m;
        for(int i=0;i<address.length();i++)
            address[i]!='.'?m+=address[i]:m+="[.]";
        return m;
    }
};

得益于string的应用

重新定义一个空字符串  

遍历一遍address遇到'.'就换成"[.]"否则就原样赋值