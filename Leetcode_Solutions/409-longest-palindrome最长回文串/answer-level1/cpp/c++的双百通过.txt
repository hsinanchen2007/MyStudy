### 总体思路
![GKL}1K}VK85R6\]~33{DATW9.png](https://pic.leetcode-cn.com/e7e7d65b9a70602c2f716bd839713d9ee94e9d06cb545fbffe04e9147e2e887e-GKL%7D1K%7DVK85R6%5D~33%7BDATW9.png)
这道题的思路分为两个部分，一个是构建哈希表，另一个是判断字符串是否回文。

### 哈希表的构建
在前两天的每日一题，拼写单词 这一题中就有哈希表的构建，当时看到了大神运用长度为26的数组进行字母次数统计，链接如下：
[https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/solution/tong-ji-zi-mu-chu-xian-de-ci-shu-shu-zu-ji-qiao-cj/]() 
在这里做了引用，针对大小写字母分别构建字符计数数组，即哈希表。见代码注释。

### 回文字符串的判断
几经调试，总结如下：
一、首先针对每一个 偶数次 与 奇数次 字母：
1.若为偶数，直接计入总长度；
2.若为奇数，将该奇数减去1 计入总长度；
3.若计算中有奇数次字母，总的长度在最后加上1；
具体见代码注释。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> lower = alp_couter(s, 'a'); //构建小写字母的计数数组
        vector<int> upper = alp_couter(s, 'A'); //构建大写字母的计数数组
        int ans = 0;  //总长度

        ans = max_palindrome(lower) + max_palindrome(upper);  //将大写 与小写 的最大长度相加
        return if_exists_odd(lower) || if_exists_odd(upper)? ++ans : ans;//存在奇数次 计数的字母，则ans再+1返回
    }                                                                    //不存在，直接返回ans
    //字母计数数组的构建，demo只取'a'或 'A'
    vector<int> alp_couter(string test, char demo) {
        vector<int> count(26, 0); //将26个值赋初值0
        for(int i = 0; i != test.length(); ++i) {             
            if(test[i] - demo >= 0 && test[i] - demo <= 25) { //若字符在字母表之间，进行计数
                ++count[test[i] - demo];
            } 
        }
        return count;
    }
    //计算最大回文长度
    int max_palindrome(vector<int>& alp) {
        int tra, len = 0;
        for(tra = 0; tra != alp.size(); ++tra) {
            if(alp[tra]) { 
                if(alp[tra] % 2 == 0) {  //若字母的计数为偶数，直接加到总长度
                    len += alp[tra];
                }
                else if(alp[tra] % 2 != 0 && alp[tra] > 2) { //若字母的计数为大于2的计数，减去1加到总长度
                    len += alp[tra] - 1;                     //这里不用考虑计数为1的字母
                }                                            //因为待所有的计数完毕，若存在计数数值为奇数
            }                                                //则直接再加上1 即为最终的总长度
        }
        return len;
    }
    //判断计数数组中是否含有计数为奇数的字母
    bool if_exists_odd(vector<int> alp) {
        for(int tra = 0; tra != alp.size(); ++tra) {
            if(alp[tra] % 2 != 0) {  
                return true; //找到奇数 计数的字母后 返回true
            }
        }
        return false; //未找到 ,返回false
    }
};