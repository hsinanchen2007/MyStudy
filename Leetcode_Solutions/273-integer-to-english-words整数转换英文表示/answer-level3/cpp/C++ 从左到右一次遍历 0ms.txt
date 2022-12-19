![屏幕快照 2020-03-24 17.05.19.png](https://pic.leetcode-cn.com/a3f807874a5e26ab347b5e8e67d51f1482d5bd0e935c50b9fc17168845fcc1b7-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-24%2017.05.19.png)

三个三个一组，每组内的翻译都是一样的；
利用当前位置到最右位置的距离来判断当前处于哪个数量级的翻译，每翻译完一组，加上对应数量级的单词；
遇到很多坑，要注意，比如1010，不能输出Hundred，比如1000000，不能输出Thousand；
对空格的处理最好是放在映射数组中。

```
class Solution {
public:
    string numberToWords(int num) {
        if(num < 0) return "";
        if(num == 0) return "Zero";
        string numStr = to_string(num);
        string scale2word[4] = {"", "Thousand ", "Million ", "Billion "};
        string tens2word[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        string small2word[20] = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        string res = "";
        int curLen = int(numStr.size()) % 3;
        if(curLen == 0) curLen = 3;
        int ind = 0;
        int nextInd = ind + curLen; // nextInd 为三个一组的组边界位置
        string tmpRes = "";
        while(ind < numStr.size())
        {
            if(nextInd - ind == 3) // 百位
            {
                tmpRes += small2word[numStr[ind]-'0'];
                if(tmpRes.size())
                {
                    tmpRes += "Hundred ";
                }
            }
            else if(nextInd - ind == 2) // 十位
            {
                int tmpVal = stoi(numStr.substr(ind, 2));
                if(tmpVal < 20)
                {
                    tmpRes += small2word[tmpVal];
                    ind++;
                }
                else
                {
                    tmpRes += tens2word[numStr[ind]-'0'];
                }
            }
            else if(nextInd - ind == 1) // 个位
            {
                tmpRes += small2word[numStr[ind]-'0'];
            }
            else // 这一组翻译完成
            {
                res += tmpRes;
                if(tmpRes.size())
                {
                    res += scale2word[((int(numStr.size())-ind) / 3)]; // 加上数量级单词
                }
                tmpRes = "";
                nextInd = ind + 3;
                ind--;
            }
            ind++;
        }
        res += tmpRes;
        while(res.size() && res.back() == ' ')
        {
            res.pop_back();
        }
        return res;
    }
};
```

