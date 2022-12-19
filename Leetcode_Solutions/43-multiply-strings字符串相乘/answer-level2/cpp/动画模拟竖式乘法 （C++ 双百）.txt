**经评论提醒，图片有误，请注意！**

![演示文稿1.gif](https://pic.leetcode-cn.com/7a5cea144918472fb76e759d982e6e145ba4f3d4ab598447fbf1de5bba42b671-%E6%BC%94%E7%A4%BA%E6%96%87%E7%A8%BF1.gif)

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        vector<int> result(num1.size() + num2.size() + 1, 0);
        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                result[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = result.size() - 1; i > 0; i--) {
            if (result[i] < 10) continue;
            result[i-1] += result[i] / 10;
            result[i] %= 10;
        }
        string r = "";
        bool zero = true;
        for (int i = 0; i < result.size() - 1; i++) {
            if (zero && result[i] == 0) continue;
            zero = false;
            r.push_back(result[i]+'0');
        }
        return r;
    }
};
```

![image.png](https://pic.leetcode-cn.com/6aeae4d75886ca4b58b12d136426e7eef661c9fc01a6c550d9886da74087f9c7-image.png)
