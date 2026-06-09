### 解题思路
题目其实具有很大的提示性n!种排列，所以可以一步一步取值，以第一个元素为例:
如果余数为0，第一个元素的值==k/((n-1)!)
否则，第一个元素的值==k/((n-1)!)+1

### 代码

```cpp
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n==1){
            return "1";
        }
        string res = "";
        if(k>jiecheng(n)){
            return res;
        }
        vector<int> ele{};
        for(int i=1;i<=n;i++){
            ele.push_back(i);
        }
        int temp = k;
        for(int i=0;i<n;i++){
            int j = jiecheng(n-i-1);
            int c = temp/j;
            temp = temp%j;
            if(temp==0){
                res.append(to_string(ele[c-1]));
                ele.erase(ele.begin()+c-1);
                for(int x=ele.size()-1;x>=0;x--){
                    res.append(to_string(ele[x]));
                }
                return res;
            }
            res.append(to_string(ele[c]));
            ele.erase(ele.begin()+c);
            if(temp==1){
                for(auto x:ele){
                    res.append(to_string(x));
                }
                return res;
            }
        }
        return res;
    }
    int jiecheng(int n){
        if(n==0||n==1){
            return 1;
        }
        int res = 1;
        for(int i=n;i>=1;i--){
            res = res * i;
        }
        return res;
    }
};
```