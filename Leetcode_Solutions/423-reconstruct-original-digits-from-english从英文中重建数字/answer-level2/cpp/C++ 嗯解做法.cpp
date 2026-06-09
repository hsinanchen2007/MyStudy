就嗯解，笨人用笨方法

```
class Solution {
public:
    bool checkZero(vector<int>& a){
        if(a[int('z'-'a')]>=1 && a[int('e'-'a')]>=1 && a[int('r'-'a')]>=1 && a[int('o'-'a')]>=1){
            a[int('z'-'a')]--;
            a[int('e'-'a')]--;
            a[int('r'-'a')]--;
            a[int('o'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkOne(vector<int>& a){
        if(a[int('o'-'a')]>=1 && a[int('n'-'a')]>=1 && a[int('e'-'a')]>=1){
            a[int('o'-'a')]--;
            a[int('n'-'a')]--;
            a[int('e'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkTwo(vector<int>& a){
        if(a[int('t'-'a')]>=1 && a[int('w'-'a')]>=1 && a[int('o'-'a')]>=1){
            a[int('t'-'a')]--;
            a[int('w'-'a')]--;
            a[int('o'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkThree(vector<int>& a){
        if(a[int('t'-'a')]>=1 && a[int('h'-'a')]>=1 && a[int('t'-'a')]>=1 && a[int('e'-'a')]>=2){
            a[int('t'-'a')]--;
            a[int('h'-'a')]--;
            a[int('r'-'a')]--;
            a[int('e'-'a')]-=2;
            return true;
        }
        return false;
    }
    bool checkFour(vector<int>& a){
        if(a[int('f'-'a')]>=1 && a[int('o'-'a')]>=1 && a[int('u'-'a')]>=1 && a[int('r'-'a')]>=1){
            a[int('f'-'a')]--;
            a[int('o'-'a')]--;
            a[int('u'-'a')]--;
            a[int('r'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkFive(vector<int>& a){
        if(a[int('f'-'a')]>=1 && a[int('i'-'a')]>=1 && a[int('v'-'a')]>=1 && a[int('e'-'a')]>=1){
            a[int('f'-'a')]--;
            a[int('i'-'a')]--;
            a[int('v'-'a')]--;
            a[int('e'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkSix(vector<int>& a){
        if(a[int('s'-'a')]>=1 && a[int('i'-'a')]>=1 && a[int('x'-'a')]>=1){
            a[int('s'-'a')]--;
            a[int('i'-'a')]--;
            a[int('x'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkSeven(vector<int>& a){
        if(a[int('s'-'a')]>=1 && a[int('v'-'a')]>=1 && a[int('n'-'a')]>=1 && a[int('e'-'a')]>=2){
            a[int('s'-'a')]--;
            a[int('v'-'a')]--;
            a[int('n'-'a')]--;
            a[int('e'-'a')]-=2;
            return true;
        }
        return false;
    }
    bool checkEight(vector<int>& a){
        if(a[int('e'-'a')]>=1 && a[int('i'-'a')]>=1 && a[int('g'-'a')]>=1 && a[int('h'-'a')]>=1 && a[int('t'-'a')]>=1){
            a[int('e'-'a')]--;
            a[int('i'-'a')]--;
            a[int('g'-'a')]--;
            a[int('h'-'a')]--;
            a[int('t'-'a')]--;
            return true;
        }
        return false;
    }
    bool checkNine(vector<int>& a){
        if(a[int('i'-'a')]>=1 && a[int('e'-'a')]>=1 && a[int('n'-'a')]>=2){
            a[int('i'-'a')]--;
            a[int('e'-'a')]--;
            a[int('n'-'a')]-=2;
            return true;
        }
        return false;
    }
    string originalDigits(string s) {
        if(s.empty()) return s;
        vector<int> a(30,0);
        for(char c:s)
            a[int(c-'a')]++;
        string res = "";
        while(checkZero(a))
            res += '0';
        while(checkSix(a))
            res += '6';
        while(checkEight(a))
            res += '8';
        while(checkTwo(a))
            res += '2';
        while(checkThree(a))
            res += '3';
        while(checkFour(a))
            res += '4';
        while(checkFive(a))
            res += '5';
        while(checkSeven(a))
            res += '7';
        while(checkOne(a))
            res += '1';
        while(checkNine(a))
            res += '9';
        sort(res.begin(),res.end());
        return res;
    }
};
```
