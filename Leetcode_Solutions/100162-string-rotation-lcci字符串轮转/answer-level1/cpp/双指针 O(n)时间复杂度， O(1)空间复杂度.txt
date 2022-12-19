![截屏2020-02-25下午3.08.08.png](https://pic.leetcode-cn.com/24bd62473b4f86720c38da2900a76889a7ebf1ebc49abfa0952ba0f4f2d91cd5-%E6%88%AA%E5%B1%8F2020-02-25%E4%B8%8B%E5%8D%883.08.08.png)

基本思路是先排除一些特殊情况，然后根据s1的字头去寻找s2中有多少个字母符合，从这些字母开始，双指针对比两个字符串是否相同。
要注意在一次对比内只要发现一个字符不符合就结束该循环
但在不同的开始位置之间是 或 的关系，只要从一个地方开始能够对的上，最终结果就是true

```
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1.size() == 0) return true;
        int length = s1.size();
        
        vector<int> begins;
        bool ans = 0;
        for (int i = 0; i<length; i++){
            if (s2[i] == s1[0])
                begins.push_back(i);
        }
        
        for (int k=0;k<begins.size();k++){
            int i = begins[k];
            int j = 0;
            bool ans_ = 1; //用来标志从begins[k]开始是否能match
            while(i<length){
                if (s2[i] != s1[j]){
                    ans_ &= 0;
                    break;
                }
                else{
                    i++;
                    j++;
                }
            }
            i = 0;
            while(j<length){
                if (s2[i] != s1[j]){
                    ans_ &= 0;
                    break;
                }
                else{
                    i++;
                    j++;
                }
            }

            ans |= ans_; //对begins中每个元素开始的所有对比进行或运算
        }
        return ans;
    }
};
```
