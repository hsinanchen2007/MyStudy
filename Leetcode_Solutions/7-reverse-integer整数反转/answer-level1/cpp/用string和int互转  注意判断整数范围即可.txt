class algori {
public:
    string& reverseInt(string& s){
        reverse(s.begin(), s.end());
        return s;
    }
};
class Solution {
    algori p;
public:
    int reverse(int x) {
        string res;
        double cnt = 0.0;
        if(x == 0){
            return 0;
        }
        else if(x < 0){
            int flag = 0;
            double j=1.0;
            if(x <= -pow(2,31)) return 0;
            x = -x;
            string now = to_string(x);
            now = p.reverseInt(now);
            res = now;
            for(int i=res.length()-1; i>=0; i--){
                if(res[i] == '0' && !flag) continue;
                else{
                    flag = 1;
                    cnt += (res[i]-'0')*j;
                    j *= 10;
                }
            }
            return cnt >= pow(2,31) ? 0 : int(-cnt);
        }
        else{
            int flag  =0;
            double j=1.0;
            string now = to_string(x);
            now = p.reverseInt(now);
            res = now;
            for(int i=res.length()-1; i>=0; i--){
                if(res[i] == '0' && !flag) continue;
                else{
                    flag = 1;
                    cnt += (res[i]-'0')*j;
                    j *= 10;
                }
            }
            return cnt >= pow(2,31) ? 0 : int(cnt);
        }
    }
};
