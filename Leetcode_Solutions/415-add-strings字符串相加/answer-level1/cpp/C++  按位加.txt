### 解题思路
![image.png](https://pic.leetcode-cn.com/cfba7e826579d3171a84b666ef945c590ca80ac3c815180625511236ee2645d5-image.png)

从各自的个位字符开始往左边推进，cur代表当前需要进位多少。
### 代码

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size(),len2 = num2.size();
        int cur = 0;//初始化的进位位为0
        int len3 = max(len1,len2);
        string res(len3,'0');
        int left = len1-1,right = len2-1;
        int tmp=0;
        while(left>=0 || right>=0){
            if(left>=0 && right>=0) tmp = num1[left--] - '0' + num2[right--] - '0' + cur;
            else if(left>=0) tmp = num1[left--] - '0' + cur;
            else tmp = num2[right--] - '0' + cur;
            cur = tmp/10;  //进位位
            tmp = tmp%10;  //当前位
            res[len3-1]+= tmp;  //res中已经初始化字符'0'了，因此这里不需要再加'0'
            len3--;
        }
        if(cur==1) res = '1'+ res;
        return res;
        
    }
};
```