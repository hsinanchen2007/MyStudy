### 解题思路
逻辑比较简单：
1.使用map储存 字母(key)与其对应的次数(value)
2.map储存过程中会用到非常关键的map中count方法
3.遍历map,根据次数奇偶来判断是否纳入最大度的累加
   1.是偶数直接累加
   2.是大于1的奇数就将该key对应的value 减去1 再累加，且说明最长回文肯定是个奇数，在最终计算偶数的基础上加1即可
   3.等于1的情况下，说明就一个字母，假如其余全部为偶数，最终次数加1 即可（注意与2.中不能重复加1，因为奇数加1次就行，不能多加）

具体代码如下：

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {

        map<char,int> mp;
        int flag = 0;
        int sum = 0;
        for(int i = 0;i<s.size();i++){
          
            if(mp.count(s[i]) == 0){
                mp[s[i]] = 1;
            }
            else{
                mp[s[i]]++;
            }
        }

        map<char,int>::iterator iter;
        iter = mp.begin();
        while(iter!=mp.end()){

            if(iter->second%2 == 0){
                sum += iter->second;
            }
            else if(iter->second>1){
                sum += iter->second-1;
                flag = 1;
            }
            else{
                flag = 1;
            }
            
            iter++;
        }

        return sum+flag;
    }
};
```