### 解题思路
扫了一眼题目  看了第一个样例以为是求RLRRLLRLRL中最大平衡字符串的RRLL的总数  发现真相的我眼泪掉下来

我改还不行吗   仔细看了三个案例 以为必须要连续的平衡字符串才计数    否则算错误如RLRRRLLR一律按1处理 发现真相的我再次泪目

第三次  在深夜一人孤独奋斗百思不得其解之后问了同为蓝桥杯奋战的兄弟  豁然开朗    安心地睡去了


注意注意注意：一定要多读几遍题目多读几遍    题目看不懂的可以去问小绿鸡或者去看评论区    有没有大神一起刷题可以带带小弟的

感谢您花了10几秒看了我这弱鸡的艰难AC路  如果想一起刷题非常欢迎呢

### 代码

```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0;
        int temp=s[0];
        int num1=0,num2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==temp)num1++;  //前置计数
            else if(temp!=s[i]){num2++;}
            if(num1==num2){
                count++;
                num1=0;
                num2=0;
            }
        }
        return count;
    }
};
```