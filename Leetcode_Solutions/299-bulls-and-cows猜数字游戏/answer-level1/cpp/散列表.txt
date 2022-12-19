### 解题思路


### 代码

```cpp
class Solution {
public:
    string getHint(string secret, string guess) {
        int A=0;
        int B=0;
        int hash1[10];
        int hash2[10];
        for(int i=0;i<10;i++)hash1[i]=hash2[i]=0;
        for(int i=0;i<secret.size();i++)
        if(secret.at(i)==guess.at(i))
        A++;
        else{ 
            hash1[secret.at(i)-'0']++;
            hash2[guess.at(i)-'0']++;
        }
        for(int i=0;i<10;i++)
        if(hash2[i]!=0)
        B+=hash1[i]<hash2[i]?hash1[i]:hash2[i];
        int exA=0;
        int exB=0;
        for(;pow(10,exA)<=A;exA++);
        for(;pow(10,exB)<=B;exB++);
        exA--;
        exB--;
        string res="";
        if(A==0)
        res.push_back('0');
        else{
            for(int i=exA;i>=0;i--)
            res.push_back(A/(static_cast<int>(pow(10,i)))%10+'0');
        }
        res.push_back('A');
        if(B==0)
        res.push_back('0');
        else{
            for(int i=exB;i>=0;i--)
            res.push_back(B/(static_cast<int>(pow(10,i)))%10+'0');
        }
        res.push_back('B');
        return res;
    }
};
```