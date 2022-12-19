### 解题思路

### 代码

```cpp
class Solution {
public:
    int maxRepOpt1(string text) {
        int len = text.size();
        vector<int> cnt(26, 0);//记录各个字符在text中出现的次数
        for(int i = 0; i < len; i++)
            cnt[text[i]-'a']++;
        //从左向右挨个字符遍历
        char cur_c = text[0];//当前单字符
        int cur_l = 1;//当前单字符串长度
        int idx = 1;//当前遍历到的字符索引
        int ans = -1;//答案
        while(idx < len){
            while(idx < len && text[idx] == cur_c){
                idx++;
                cur_l++;
            }
            if(cur_l < cnt[cur_c-'a']){//可以把某个位置的cur_c交换到idx位置，使单字符串得以延长
                cur_l++;
                int tmp = idx + 1;//继续向后延长单字符串
                while(tmp < len && text[tmp] == cur_c){
                    cur_l++;
                    tmp++;
                }
            }
            //当aaaba这种情况时，前"交换"的a会在继续延长时再次计数，所以要取min，达到去重的作用
            cur_l = min(cur_l, cnt[cur_c-'a']);
            ans = max(ans, cur_l);
            if(idx < len){//继续记录下一段单字符串
                cur_c = text[idx];
                cur_l = 1;
                idx++;
            }
        }
        return ans;
    }
};
```