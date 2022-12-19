### 解题思路
看很多答案都是用了递归地方法，其实不用递归也可以的，思路如下
假设digits的长度为 len, int col = len
digits中所有数字 对应字母个数的乘积 为row
建立数组 char[row][col] res，//对应代码中的vector<string> res(row,string(col, ' '));
只要用把数组res正确填充完毕，其实就是我们要的答案了。
填充的方法，从最后一列开始,用digits[len-1]对应的字符(并记录字母个数**count**)从上到下依次循环填充，直到最后一行,例如abc,就填a,填b，填c,填a···
倒数第二列，对应的字母序列为digits[len-2]，每个字母重复填充**count**次，依次到最后一行，更新count *= （digits[len-2]对应字母个数）
···
直到填充完第一列，char[row][col] res;就是最终的结果了
时间复杂度应该是O=(len_num1*len_num2*len_num3···)=4的digitl_len次方=0

### 代码

```cpp
class Solution {
public:
    vector<string> letterCombinations(string digits) {
     vector<string> v;
        if(digits.length()<1){return v;}
        vector<string> vec_data;//{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vec_data.push_back("abc");
        vec_data.push_back("def");
        vec_data.push_back("ghi");
        vec_data.push_back("jkl");
        vec_data.push_back("mno");
        vec_data.push_back("pqrs");
        vec_data.push_back("tuv");
        vec_data.push_back("wxyz");

        int digits_len = digits.length();
        int row = 1;
        const int col = digits_len;

        for(int l =0;l<digits_len;++l){
            row *= vec_data[digits[l]-'2'].length();
        }

        //建立数组 char[row][col]，所有字符初始化为空格
        vector<string> res(row,string(col, ' '));
        int mi = 1;
        for(int j=col-1;j>-1;--j){
            //resArr[i][j];
            string cur_str = vec_data[digits[j]-'2'];
            int cur_len = cur_str.length();
            for(int k=0;k<row;k){
                for(int n=0;n<cur_str.length();++n){
                    char c = cur_str[n];
                    for(int x=0;x<mi;++x){
                        //resArr[k][j]= k% vector_data[j].length();
                        res[k][j] = c;
                        if(x<mi)++k;
                    }
                    //++k;
                }
                
            }
            mi = mi * cur_len;
        }
        return res;
    }
};
```