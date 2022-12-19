```
/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++){
            if (str[i]<='Z'&&str[i]>='A'){
                str[i]+=32;
            }            
        }       
        return str;
    }
};


```
