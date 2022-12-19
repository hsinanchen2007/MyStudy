![image.png](https://pic.leetcode-cn.com/5805220bf5d1e45ae6537beae4594900b8be97498befb0f16c45e7118e6e4891-image.png)

### 解题思路
所谓报数，就是根据s1，报出一个s2.
1. 首先我手上拿着s1的第1个数字number，并且配套的count = 1.
2. 然后我看s1的第2个数字，哦，和我手上拿着的number相同，那我就让count++
3. 然后我看s1的第3个数字，哦，和我手上拿着的number还相同，那我就还让count++
4. 然后我看s1的第4个数字，哦，和我手上拿着的不同，那我做两件事：
        1. “打印”我手上的number和count
        2. 将这个新发现的不同的数字拿在我手上，并且将count置1.
5. 然后我看s1的第5个数字，哦，你没有第5个数字啦？那说明我读完了，但是报数还没报完，还要将我手上的number和count都“打印出来”才算报完了s1，得到了s2。
**打印**的意思就是将count和number连接到s2的末尾。
### 补充
    这个打印的方法我用的是直接加，如果用to_string的方法将数字转成字符串再加到末尾也可以，但是效率会减少非常多。
### 代码

```cpp
class Solution {
public:

    string countAndSay(int n) {
        string s1 = "1",s2 = "";  
        if(n == 1) return s1;
        for(int i=1; i<n; i++){//类似于动态规划的自底向上计算，知道第n-1个，才能知道第n个
            int count = 1;
            int number = s1[0] - '0';
            int j = 1;
            while(j<s1.size()){
                if(s1[j]-'0' == number){// 相等，就让count++，然后看下一个
                    count++;
                    j++;
                }else{ // 不相等，遇到新的了，先打印，再用手拿起新的数，重置count
                    s2 +=(count+'0');
                    s2 += (number+'0');
                    number = s1[j] - '0';
                    count = 1;
                    j++;
                }
            }
            // 读完了，将手上拿着的数字number和count都打印出来
            s2 += (count+'0');
            s2 += (number+'0');
            // 下面两句类似于用迭代法求斐波那契数列
            s1 = s2;
            s2 = "";
        }
        return s1;
    }
};
```