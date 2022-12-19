class Solution {
public:
    
    int char2int(char c){
        return c-'0';
    }
    
    string addStrings(string num1, string num2) {
        int l1 = num1.size(),l2 = num2.size();
        int len = l1 > l2 ? l1 : l2;
        //下面两个while循环是给两数中的较短者，在其前面补0
        while(l1 < len){
            num1 = '0' + num1;
            l1++;
        }
        while(l2 < len){
            num2 = '0' + num2;
            l2++;
        }
        int tmp = 0;
        string str = "";
        for(int i = len - 1;i >= 0;i--){
            tmp += (char2int(num1[i]) + char2int(num2[i]));
            str = to_string(tmp%10) + str;
            tmp /= 10;
        }
        //是否最高位产生了进位
        if(tmp != 0)
            str = "1" + str;
        
        return str;
    }
};
