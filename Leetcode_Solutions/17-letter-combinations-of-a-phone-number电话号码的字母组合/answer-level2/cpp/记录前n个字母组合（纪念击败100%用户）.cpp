### 解题思路
此处撰写解题思路
执行用时 :0 ms
, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7 MB
, 在所有 C++ 提交中击败了100.00%的用户
### 代码
第一次提交击败100%，看了下题解，有人也有同样思路。本次记录下做个纪念。
查找所有组合，暴力循环肯定不可取。考虑到每多一个数字，就是把前N个数字组成的所有串，再和当前数字对应的各个字符再组一遍，所以每次逐步把前n个记录下来和下一个数字匹配即可。
比如：数字23456
第一次2对应a,b,c ==> string2vector
第二次23对应string2vector+d, string2vector+e, string2vector+f ==> string3vector
第三次234对应string3vector+g, string3vector+h, string3vector+i  ==> string4vector
...
以此类推

```cpp
class Solution {
public:
    map<string,string> getDigTable() {
        map<string,string> digitsTableMap;
        digitsTableMap.insert(make_pair("2","abc"));
        digitsTableMap.insert(make_pair("3","def"));
        digitsTableMap.insert(make_pair("4","ghi"));
        digitsTableMap.insert(make_pair("5","jkl"));
        digitsTableMap.insert(make_pair("6","mno"));
        digitsTableMap.insert(make_pair("7","pqrs"));
        digitsTableMap.insert(make_pair("8","tuv"));
        digitsTableMap.insert(make_pair("9","wxyz"));
        return digitsTableMap;
    }
    vector<string> letterCombinations(string digits) {
        map<string,string> digitsTableMap = getDigTable();
        vector<string> digitsVec;
        for(int i=0; i<digits.length(); i++) {
            digitsVec.push_back(digitsTableMap[digits.substr(i,1)]);
        }

        vector<string> resultVec;
        for (auto ds:digitsVec) {
            if (resultVec.empty()) {
                for(int i=0; i<ds.length(); i++) {
                    resultVec.push_back(ds.substr(i,1));
                }
                continue;
            }

            vector<string> tmpVec;
            for (auto dr:resultVec) {
                for(int i=0; i<ds.length(); i++) {
                    tmpVec.push_back(dr+ds[i]);
                }
            }

            resultVec.clear();
            resultVec = tmpVec;
        }
        return resultVec;
    }
};
```