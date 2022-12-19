 `c++`  递归，英文计数有个特点就是每三位断一次，不像中文计数是按每四位断一次

```dart
const string tmp19[20] = {"One ", "Two ", "Three ", "Four ", "Five ", "Six ",
				"Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ",
				"Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ",
				"Eighteen ", "Nineteen "};
    const string tmp90[8] = { "Twenty ", "Thirty ", "Forty ", "Fifty ",
				"Sixty ", "Seventy ", "Eighty ", "Ninety " };
    const string types[3] = {"Billion ","Million ","Thousand "};
    string numberToWords(int num) {
        string s;
        if(!num) return "Zero";
        int idx = 1000000000;
        int i = 0;
        while(i < 3){
            int t = num /idx;
            if(t) s += to999(t) + types[i];
            num %= idx;
            idx /= 1000;
            i++;
        }
        if(num) s += to999(num);
        return s.substr(0,s.size() - 1);
    }
    string to19(int num){
        if(num < 1) return "";
        return tmp19[num - 1];
    }
    string to999(int num){
        if(num < 100) return to99(num);
        return to19(num / 100) + "Hundred " + to99(num % 100);
    }
    string to99(int num){
        if(num < 20) return to19(num);
        return tmp90[(num / 10) - 2] + to19(num % 10);
    }
```
 