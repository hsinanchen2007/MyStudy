### 解题思路
此处撰写解题思路
最多一共是10位数，a bcd efg hig,a位十亿位，bcd,efg,hig可以相同的函数求解，只不过在efg和hig之间当efg不都为零时要加一个Thousand,在bcd与efg间同理，加Hundred时要注意三位数是否为0.
### 代码

```cpp
class Solution {
public:
    string ans = "";
    string numberToWords(int num) {
        if (num==0)
        return "Zero";
        int rec = 0;
        long long int rec2 = 0;
        int rec1;
        while (num){
            rec1 = num%10;
            rec2 = (rec2*10)+rec1;
            num /= 10;
            rec++;
            if (rec%3==1){
                rec1 = num%10*10+rec1;
                rec2 = (rec2*10)+rec1;
                num /= 10;
                rec++;
                appandAns1(rec1);
            }else if (rec%3==0&&rec2!=0&&rec1!=0){
                rec2 = 0;
                ans = "Hundred "+ans;
                ans = getUnit(rec1)+" "+ans;
            }
            if (num!=0){
                if (rec==3&&(num%1000)!=0)
                ans = "Thousand "+ans;
                else if (rec==6&&(num%1000)!=0)
                ans = "Million "+ans;
                else if (rec==9)
                ans = "Billion "+ans;
            }
        }
        ans = ans.erase(ans.length()-1,1);
        return ans;
    }
    string getUnit(int num){
        if (num==1)
            return "One";
        else if (num==2)
            return "Two";
        else if (num==3)
        return "Three";
        else if (num==4)
        return "Four";
        else if (num==5)
        return "Five";
        else if (num==6)
        return "Six";
        else if (num==7)
        return "Seven";
        else if (num==8)
        return "Eight";
        else if (num==9)
        return "Nine";
        return "";
    }

    string getDozen(int num){
        if (num==10)
        return "Ten";
        else if (num==11)
        return "Eleven";
        else if (num==12)
        return "Twelve";
        else if (num==13)
        return "Thirteen";
        else if (num==14)
        return "Fourteen";
        else if (num==15)
        return "Fifteen";
        else if (num==16)
        return "Sixteen";
        else if (num==17)
        return "Seventeen";
        else if (num==18)
        return "Eighteen";
        else if (num==19)
        return "Nineteen";
        return "";
    }

    string getTens(int num){
        if (num==20)
        return "Twenty";
        else if (num==30)
        return "Thirty";
        else if (num==40)
        return "Forty";
        else if (num==50)
        return "Fifty";
        else if (num==60)
        return "Sixty";
        else if (num==70)
        return "Seventy";
        else if (num==80)
        return "Eighty";
        else if (num==90)
        return "Ninety";
        return "";
    }
    void appandAns1(int num){
        if (num<10){
            if (num!=0)
            ans = getUnit(num)+" "+ans;
        }else if (num<20){
            ans = getDozen(num)+" "+ans;
        }else {
            if (num%10==0){
                ans = getTens(num)+" "+ans;
            }else {
                ans = getUnit(num%10)+" "+ans;
                ans = getTens(num-num%10)+" "+ans;
            }
        }
    }
};
```