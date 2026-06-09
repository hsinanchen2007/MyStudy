好数不能含有任意1个3、4、7，而要含有至少1个2、5、6、9\n
设待判断的数字有r位，有如下三种常见解法：

方法1：硬算，时间O(nr)，空间O(1)<br/>
思路耿直，检查每个数字的每一位，逐个判断每个数字是否是好数
```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            int num = i;
            bool changed = false;
            while (num) {
                int rem = num % 10;
                if (rem == 3 || rem == 4 || rem == 7) {
                    break;
                }
                changed |= rem == 2 || rem == 5 ||
                    rem == 6 || rem == 9;
                num /= 10;
            }
            if (changed && !num) {
                count++;
            }
        }
        return count;
    }
};
```

方法2：动态规划，时间O(n)，空间O(n)<br/>
9以后的每个数n可以拆成a = n % 10（最后一位）和a = n / 10（前面r - 1位）<br/>
若a和b中均不含有3、4、7且至少有一个含有2、5、6、9，那么n就是好数<br/>
dp数组存储3种值，0：不包含3、4、7的坏数，1：含有3、4、7的坏数，2：好数<br/>
通过dp数组可以知晓a和b是否含有3、4、7或2、5、6、9，直接判断出n是否是好数
```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            if (i == 3 || i == 4 || i == 7 ||
                dp[i % 10] == 1 || dp[i / 10] == 1) {
                dp[i] = 1;
            } else if (i == 2 || i == 5 || i == 6 || i == 9 ||
                dp[i % 10] == 2 || dp[i / 10] == 2) {
                dp[i] = 2;
                count++;
            }
        }
        return count;
    }
};
```

方法3：转为字符串，时间贼慢，空间贼占<br/>
好在代码简短，转为字符串把一切交给STL来解决
```cpp
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            string num = to_string(i);
            if (num.find_first_of( "347") == -1 &&
                num.find_first_of("2569") != -1) {
                count++;
            }
        }
        return count;
    }
};
```

更多LeetCode题解：<https://github.com/gremist/LeetCode>