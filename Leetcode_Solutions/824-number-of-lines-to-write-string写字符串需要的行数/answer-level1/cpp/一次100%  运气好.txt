### 解题思路
![`XFV{}K~DI@)`5KBYU(V\[36.png](https://pic.leetcode-cn.com/5c01921d88cfc2f6788b0d76c1226e589f79b1b6d15f7cedb27f7da89d547b3a-%60XFV%7B%7DK~DI@\)%605KBYU\(V%5B36.png)


### 代码

```cpp
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int sum=0,hangNum=1,num=0;
        vector<int> res;
        for(int i=0;i<S.length();i++)
        {
            sum+=widths[S[i]-'a'];
            if(sum<=100){
                num=sum;
            }else{
                hangNum++;
                sum=widths[S[i]-'a'];
                num=widths[S[i]-'a'];
            }
        }
        res.push_back(hangNum);
        res.push_back(num);
        return res;
    }
};
```