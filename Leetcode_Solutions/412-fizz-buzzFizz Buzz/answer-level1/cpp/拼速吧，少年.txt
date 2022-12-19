直接计数就行了不用算浪费时间，遇到坑点的会卡时间，再坑点给你大数。
![拼速.png](https://pic.leetcode-cn.com/b79932eb8430de057377204e9ff165f123c3bc947b5c0ecd2715060f50374243-%E6%8B%BC%E9%80%9F.png)

```
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int i3=0,i5=0;
        vector<string>ans;
        for (int i = 1; i <=n ; i++) {
            i3=(i3+1)%3;
            i5=(i5+1)%5;
            if (i3==0&&i5==0)ans.push_back("FizzBuzz");
            else if (i3==0&&i5!=0)ans.push_back("Fizz");
            else if (i3!=0&&i5==0)ans.push_back("Buzz");
            else ans.push_back(to_string(i));
        }
        return ans;
    }
};
```
