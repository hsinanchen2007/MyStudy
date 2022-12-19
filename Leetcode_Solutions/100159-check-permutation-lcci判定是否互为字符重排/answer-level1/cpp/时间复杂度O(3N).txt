```
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        // 法1：排序，然后比较,时间复杂度O(NlogN)
        // 法2: 数各字符个数然后查看是否相等，map或者数组都可,时间复杂度O(3N)
        int counter_s1[256] = {0};
        int counter_s2[256] = {0};
        for(char c : s1) counter_s1[c]++;
        for(char c : s2) counter_s2[c]++;

        for(int i=0; i<256; i++) 
            if(counter_s1[i] != counter_s2[i]) return false;
        return true;        
    }
};
```
