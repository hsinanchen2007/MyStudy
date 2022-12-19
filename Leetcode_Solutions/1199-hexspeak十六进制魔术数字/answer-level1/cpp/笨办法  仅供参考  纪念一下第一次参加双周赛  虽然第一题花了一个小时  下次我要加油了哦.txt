class Solution {
public:
    string toHexspeak(string num) {
        long long a = stoll(num);
        string b;
        if(a>=1&&a<=pow(10,12)){
        string p[1000];
        int i = 0;

        while (a > 0) {
            int m = a % 16;
            string temp;
            if (m >= 10 && m <= 15 || m == 0 || m == 1) {
                switch (m) {
                case 0: temp = 'O'; break;
                case 1: temp = 'I'; break;
                case 10:temp = 'A'; break;
                case 11:temp = 'B'; break;
                case 12:temp = 'C'; break;
                case 13:temp = 'D'; break;
                case 14:temp = 'E'; break;
                case 15:temp = 'F'; break;
                }
                p[i++] = temp;
            }
            else {
                temp = to_string(m);
                p[i++] = temp;
            }
            a = a / 16;
        }
        for (i = i - 1; i >= 0; i--) {
            b += p[i];
        }

        bool flag = false;
        for (int i = 0; i < b.length(); i++) {
            if (b[i] >= 50 && b[i] <= 56) {
                flag = true;
                cout << "ERROR";
                b="ERROR";
                break;
            }
        }
        if (!flag)
        cout << b;  
        
        }
        else{
            b="ERROR";
        }
        return b;
            
    }
};

注意测试数据范围哦  设置为long long