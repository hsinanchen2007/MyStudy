### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isDivisible(string str1, string str2, string& tmpGCD){
    int len = tmpGCD.size();
    for (int i = 0; i < str1.size(); i += len) {
        string tmp = str1.substr(i, len);
        if(tmp != tmpGCD){
            return false;
        }
    }

        for (int i = 0; i < str2.size(); i += len) {
            string tmp = str2.substr(i, len);
            if(tmp != tmpGCD){
                return false;
            }
        }

    return true;

}
int gcp(int num1, int num2){
    if(num2 == 0){
        return num1;
    }
    return gcp(num2, num1 % num2);
}

string gcdOfStrings(string str1, string str2) {
    string tmpGCD;
    tmpGCD = str1.size() > str2.size() ? str2 : str1;
    int largerSize = str1.size() > str2.size() ? str1.size() : str2.size();
    int i = str1.size() > str2.size() ? gcp(str1.size(), str2.size()) : gcp(str2.size(), str1.size());

    for (; i >= 1;) {
        string retString = tmpGCD.substr(0, i);
        if(isDivisible(str1, str2, retString)){
            return retString;
        }
        if(i % 2 == 0){
            i /= 2;
            i = gcp(largerSize, i);
        }
        else{
            break;
        }
    }

    return "";
}

};
```