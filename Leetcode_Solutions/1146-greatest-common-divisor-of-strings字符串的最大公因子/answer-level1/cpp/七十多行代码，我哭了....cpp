```
class Solution {
public:
    vector<int>getFactors(int x){
        vector<int>factors;
        for(int i = 1; i <= x; i++){
            if(x % i == 0) factors.push_back(i);
        }
        return factors;
    }

    string getPerid(string& s){
        int n = s.length();
        for(int d = 1; d <= n; d++){
            if(n % d == 0){
                bool ok = true;
                for(int i = 0; i < d; i++){
                    for(int k = d + i; k < n; k += d){
                        if(s[k] != s[i]){
                            ok = false;
                            break;
                        }
                    }
                    if(!ok) break;
                }
                if(ok) return s.substr(0, d);
            }
        }
        return s;
    }
    string solve(string& p1, int d1, string& p2, int d2){
        //cout << p1 << ' ' << d1 << endl << p2 << ' ' << d2 << endl;
        int n1 = p1.size();
        int n2 = p2.size();
        if(n2%n1 != 0) return "";
        for(int i = 0; i < p1.size(); i++){
            bool ok = true;
            for(int k = i; k < n2; k += n1){
                if(p2[k] != p1[i]){
                    ok = false;
                    break;
                }
            }
            if(!ok){
                return "";
            }
        }
        vector<int>f1 = getFactors(d1);
        vector<int>f2 = getFactors(d2);
        //cout<<"Ddd";
        for(int i = 0; i < f2.size(); i++){
            f2[i] *= n2/n1;
        }
        sort(f1.begin(), f1.end(), greater<int>());
        sort(f2.begin(), f2.end(), greater<int>());
        int i = 0, j = 0, c = 0;
        while(i < f1.size() && j < f2.size()){
            if(f1[i] == f2[j]){
                c = f1[i];
                break;
            }else if(f1[i] > f2[j]){
                i++;
            }else{
                j++;
            }
        }
        if(!c) return "";
        string ans = p1;
        while(--c) ans += p1;
        return ans;
    }
    string gcdOfStrings(string str1, string str2) {
        string p1 = getPerid(str1); int d1 = str1.size()/p1.size();
        string p2 = getPerid(str2); int d2 = str2.size()/p2.size();
        //cout << p1 << ' ' << p2 << endl;
        return d1 <= d2 ? solve(p1, d1, p2, d2) : solve(p2, d2, p1, d1);
    }
};
```