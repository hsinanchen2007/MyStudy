![1.png](https://pic.leetcode-cn.com/3852aa6b95b0577a1db0bb6a560c73602eedc9df3144494fb6eb248591cca26e-1.png)
```
class Solution {
public:
    //ASCII码中48表示0，97表示a
    vector<string> letterCombinations(string &digits) {
        
        vector<string> ans{};//返回值
        if(digits.size() == 0)return ans;
        vector<string> num_alp{"abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"};//构建数字--字符对应
        
        //先对第一个进行处理
        int first = digits[0] - 50;
        string letter_0 = num_alp[first];
        for(int i = 0; i < letter_0.size(); i++){
            string str1;
            char ch1 = letter_0[i];
            str1 = ch1;
            ans.insert(ans.end(), str1);
            }
        
        //先ite再add
        for(int i = 1; i < digits.size(); i++){
            string letter = num_alp[digits[i] - 50];
            ite_letter(ans, letter);//先复制
            add_letter(ans, letter);//再添加
        }
        return ans;
    }

    //在ans中每个字符串的末尾每隔size_letter插入letter中不同的字符
    vector<string> add_letter(vector<string> &ans, string letter){
        int size_ans = ans.size(), size_letter = letter.length(), temp = size_ans/size_letter;
        for(int i = 0; i < size_letter; i++){
            for(int j = 0; j < temp; j++){
                ans[j + i * temp] += letter[i];
            }
        }
        return ans;
    }

    //对字符串ans复制size_letter倍
    vector<string> ite_letter(vector<string> &ans, string letter){
        vector<string> res = ans;
        for(int i = 1; i < letter.size(); i ++){//这里起始值是1是因为已经存在ans了，只需再叠加letter.size()-1即可
            for(int j = 0; j < res.size(); j++){
                ans.insert(ans.end(), res[j]);
            }
        }
        return ans;
    }
};
```
