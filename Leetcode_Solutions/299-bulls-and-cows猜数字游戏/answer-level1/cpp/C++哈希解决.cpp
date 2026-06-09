### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
    map<char,int> M;
    map<char,int> M1;
    int male=0,female=0;
    for (int i=0; i<secret.length(); i++) {
        M[secret[i]]++;
    }
    for (int i=0; i<secret.length(); i++) {
        if (M[guess[i]]==0) {
            continue;
        }
        if (M[guess[i]]>0&&guess[i]==secret[i]) {
            M1[guess[i]]++;
            male++;
            if (M[guess[i]]<M1[guess[i]]) {
                female--;
            }
        }
        if (M[guess[i]]>0&&guess[i]!=secret[i]) {
            M1[guess[i]]++;
            if (M1[guess[i]]<=M[guess[i]]) {
                female++;
            }
        }
    }
    string result;
    result=to_string(male)+"A"+to_string(female)+"B";
    return result;
}

};
```