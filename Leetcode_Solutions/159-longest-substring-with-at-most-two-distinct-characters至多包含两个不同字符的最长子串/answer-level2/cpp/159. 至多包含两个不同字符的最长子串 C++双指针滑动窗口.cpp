### 解题思路
/* C++ 双指针滑动窗口解法
最困难的点：如何计算子字符串中不同字符的个数
1、使用一个unordered_map进行去重
2、map中的key对应字符串中的字符，value对应该字符在字符串s中的位置，取值范围[0,s.size())
3、value值得作用：map中有超过2个不同的字符时，自左至右移动左指针，直到子串中的不同字符少于3个

时间复杂度为O(s.size())

详细的解释请参考图文并茂的官方题解：https://leetcode-cn.com/problems/longest-substring-with-at-most-two-distinct-characters/solution/zhi-duo-bao-han-liang-ge-bu-tong-zi-fu-de-zui-chan/

*/

### 代码

```cpp

//指针的移动是难点
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int maxlen_substr = 0;//含有最多2个不同字符的最长子串的长度。
        int length = s.size();
        if(0 == length){
            return maxlen_substr;
        }

        int p_left_start = 0;//子串的左指针
        int num_of_element = 0;//子串中不同字符的个数，如果该值大于2说明子串中不同字符的个数已经超过2个了，需要移动左指针，直到子串中的不同字符个数＜3
        unordered_map<char,int> map_substr;//用于存储不同字符在字符串s中的位置，key是字符，value是该字符在字符串s中的索引，从0《-》s.size()-1

        for(int i = 0;i < length;i++){//从0来时遍历整个字符串
            num_of_element = num_of_element + ((map_substr.count(s[i])==0) || map_substr[s[i]] < p_left_start);//这个要好好解释一下，请看下面的解释：
            //第一个算式：(map_substr.count(s[i])==0--》如果满足条件，说明map中没有s[i],此时子串中不同字符的个数要+1
            //第二个算式：map_substr[s[i]] < p_left_start ==》 如果满足该条件，说明s[i]曾经在子串中存在过且该字符在s中的位置已经落后于子串的起始位置，说明在子串中已经不包含s[i]了，此时就需要将s[i]在s中的索引重新放到map中，最终要将子串中不同字符的个数+1
            //所以，在统计子串中不同字符的个数的时候，上述两个算式任何成立都需要将num_of_element+1
            if(num_of_element > 2){//子串中不同字符的个数超过2个时的处理逻辑
                while(map_substr[s[p_left_start]] > p_left_start){//根据左指针所指向的字符在map中所对应的位置去移动左指针
                    p_left_start++;//移动左指针
                }
                p_left_start++;//左指针+1，例子就是“abcabcabc”
                num_of_element--;//子串中不同字符个数减少1个
            }

            maxlen_substr = max(maxlen_substr,i - p_left_start + 1);//求取符合条件的子串长度
            map_substr[s[i]] = i;//保存s[i]在s中的位置
        }

        return maxlen_substr;
        
    }
};
```