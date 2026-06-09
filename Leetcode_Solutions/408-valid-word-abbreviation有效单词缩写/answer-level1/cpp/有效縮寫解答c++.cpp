### 解题思路
1. 判斷是不是數字
-   判斷是不是零
-       如果是，判斷是不是一個有效數字（根據題目意思，零不是有效縮寫的數字，但是100中的零是必須的）
-       如果不是，則計算需要右移的word位數，保存在num中
2. 如果不是數字，則使用Num右移以後判斷是否是一樣的單詞，重複循環直到結束都沒有差錯的話則返回true，否則返回false
- 


### 代码

```cpp
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int num=0;
        int i=0,j=0;
        bool isNum=false;
        while(i<word.size()&&j<abbr.size())
        {
            int temp=abbr[j]-'0'; 
            if(temp>=0&&temp<10)//是數字
            { 
                if(temp==0&&!isNum) return false;
                else if(temp!=0) isNum=true;
                num*=10;
                num+=temp;
                j++;
            }
            else//不是數字
            {
                isNum=false;
                i+=num;
                num=0;
                if(i>word.size()||abbr[j]!=word[i]) return false;
                i++;j++;
            }
        }
                i+=num;
                if(i>word.size()||abbr[j]!=word[i]) return false;
                i++;j++;
            return true;
    }
};
```