三个注意点：
1.两个字串要一样长
2.注意进位
3.求当前位

class Solution {
public:
    string addBinary(string a, string b) {
        
        int lena = a.size()-1;
        int lenb = b.size()-1;
        
        int carry = 0 ;//判断是否进位
        int sum = 0;
        string res = "";

        while(lena >=0 || lenb>=0)  //不知道哪个更长，以最长的为退出，短的在操作的时候补0
        {
            int p = lena>=0?a[lena--] -'0':0;   //小于0的时候补齐0
            int q = lenb>=0?b[lenb--] - '0':0;  //补
            sum = p+q+carry;
            res = to_string(sum%2) + res;    //求当前位的值，进位放在carry中
            carry = sum /2;                   //看是否有进位。
        }
        if(carry == 1) //最后一位还有进位。
        {
            res =  "1" + res;
        }
        return res;
    }
};