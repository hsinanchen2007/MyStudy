按照规则字面意思构造即可

代码：
```
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            string temp = "";
            if (i % 3 == 0)
                temp = temp + "Fizz";
            if (i % 5 == 0)
                temp = temp + "Buzz";
            if (i % 3 != 0 && i % 5 != 0) {
                int num = i;
                while (num) {
                    temp.insert(0, 1, (char)(num % 10 + 48));
                    num = num / 10;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```
