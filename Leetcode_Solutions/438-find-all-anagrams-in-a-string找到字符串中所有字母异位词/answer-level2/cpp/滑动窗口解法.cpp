```
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        int pattern[26] = {0};  // 用于记录p中出现的字符
        int window[26] = {0};   // 用于记录滑动窗口中出现的字符个数
        
        for(char c : p)
            pattern[c-'a']++;   // 统计字符个数
        
        vector<int> res;
        
        int left = 0,right = 0;  // 滑动窗口
        int psize = p.size();
            
        int match = 0;
        
        while( right < s.size())
        {
            if(pattern[ s[right] - 'a' ])  // 如果当前字符在字符串p中出现
            {
                window[ s[right] - 'a' ]++; // 滑动窗口记录
                int flag = 0;     
                if(right - left + 1 == psize)// 如果当前滑动窗口的大小等于p的长度
                {
                    for(int i = 0; i < 26; i++)// 遍历 pattern 和 window 数组，对应的字符出现的个数应该相同
                    {
                        if(window[i] != pattern[i])
                        {
                            flag = 1;  // 如果出现某个字符不相同，跳出循环
                            break;
                        }
                    }
                    if(!flag) // 对应字符全都相同
                    {
                        res.push_back(left); // 记录结果
                    }
                    window[ s[left] - 'a' ]--; // 此时滑动窗口的左窗口需要向前移动，减少这个左端点字符在 window数组的次数
                    left++;  // 左窗口向前推进
                }
                right++; // 右窗口向前推进
                
            }
            else //未找到这个字符
            {
                right++;          // 滑动窗口重新调整，调整到右窗口的下一个位置
                left = right;
                for(int i = 0; i < 26 ; i++) // 清除滑动窗口的数据
                    window[i] = 0;
            }
        }
        
        return res;
    }
};
```
