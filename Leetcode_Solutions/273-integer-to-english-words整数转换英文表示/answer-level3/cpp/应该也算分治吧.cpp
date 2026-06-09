
### 代码

```cpp
class Solution {
public:

    string table[2][11] = { {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"} ,
                            {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}};

    string table2[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; 

    string threeTranslate(int num){
        string ret = "";
        if(num == 0) return "";

        int n[3] = {0};
        n[0] = num % 10; num = num / 10;
        n[1] = num % 10; num = num / 10;
        n[2] = num % 10;

        if(n[0] != 0){
            ret = table[0][n[0]];
        }

        if(n[1] != 0){
            if(n[1] == 1){
                ret = table2[n[0]];
            }else{
                ret = ret.empty() ? table[1][n[1]] : table[1][n[1]] + " " + ret;
            }
        }

        if(n[2] != 0){
            ret = ret.empty() ? table[0][n[2]] + " Hundred" : table[0][n[2]] + " Hundred " + ret;
        }

        return ret;
    }

    string table3[10] = {"", "Thousand", "Million", "Billion"};

    string numberToWords(int num) {
       // return threeTranslate(num);

        if(num == 0) return "Zero";
        string ret = "";
 
        int i = 0;
        while(num > 0){
            string temp = threeTranslate(num % 1000);
            
            if(!temp.empty())
                if(ret != "")
                    ret = temp  + " " + table3[i] + " " + ret;
                else
                    ret = temp + ( table3[i] == "" ? "" : " " + table3[i] );

            num = num / 1000;
            ++i;
        }

        return ret;
    }
};
```