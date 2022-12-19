使用一个map来记录当前处理子串中包含的字符，详见代码
![image.png](https://pic.leetcode-cn.com/40b512978ea1c62ac7713ed09561f6df6c361b6c47a997fbac3efbb773155d47-image.png)

```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {    //滑动窗口
        int len = s.length();
        if(!len)
            return 0;
        int low=0, high=0, maxlen=0;
        map<char, bool> existence_map;  //记录已经包含在子串中的char
        while(high<len && low<=high){
            //high对应的char已经被记录过
            if(existence_map.find(s[high]) != existence_map.end()){
                if(existence_map[s[high]] == false){
                    //若high对应的char不在当前子串中，则窗口右扩，更新maxlen值和map
                    existence_map[s[high]] = true;
                    high++;
                    maxlen = high-low>maxlen ? high-low:maxlen;
                }
                else{
                    //high对应的char已在子串中，窗口左侧右移，更新map
                    existence_map[s[low]] = false;
                    low++;
                }
            }
            ////high对应的char未被记录过，即从未出现过
            else{
                existence_map[s[high]] = true;
                high++;
                maxlen = high-low>maxlen ? high-low:maxlen;
            }

        }
        return maxlen;
    }
};
```
