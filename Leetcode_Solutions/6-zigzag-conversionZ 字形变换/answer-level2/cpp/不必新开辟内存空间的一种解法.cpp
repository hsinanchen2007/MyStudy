### 8ms & 8.1mb
![1.png](https://pic.leetcode-cn.com/d791df51c20148f6d630189237bdff5407f5d4a9872bdb4cfe79cfeb353132fb-1.png)
# 这是一道找规律题
## 思路：
    从输出的顺序着手，既然是逐行输出，那我们就逐行找到排列规律。
    先假设给定了变换后为N（N>=2）行，字符串长度 lenth。不难发现，
    我们逐行输出的一定是'Z'形的直列和两直列之间的元素，所以，
    第i行一共要输出起始位s[i]('Z'的直列),s[i+2*(N-1-i)]('Z'的倾斜列),s[i+2*(N-1)](下一个直列)...
    如此重复数次，结束第i行，注意，如果是第一行和最后一行的元素，两直列之间不存在元素，
    这时直接跳过中间步骤就好。
    N>=2就这样处理完毕，N=1时，原封不动把传进来的字符串return就行。
    既然找到了规律，大可放弃开辟空间存放元素的想法，用嵌套的两层循环实现得到排列好的每一行
### 代码

```cpp
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans_str("");
        const int LEN = s.length();
        int t(0);
        if(numRows==1)  //只有一行就直接返回
            return s;
        for(int i=0 ;i < numRows;i++){
            t=i;        //t现在是每一行第一个元素的索引
            //这里先判断倾斜列元素是否存在
            for(;(t+2*(numRows -(i+1)) < LEN) && numRows!=1;){
                 ans_str += s[t];
                 if(  i!=0 && i!= numRows-1 ){
                     ans_str += s[t+2*(numRows -(i+1))];
                 }
                 t += 2*numRows - 2;//跳到下一个直列的位置
             }
        //存在一种情况是t到了该行的末尾，然而这个末尾元素就在竖直列，无法进入下一次内层循环，
        //那么，就把它添加到我们的结果串中
             if(t<LEN)
                ans_str+=s[t];
        }
        return ans_str;
    }
};
// @lc code=end
```