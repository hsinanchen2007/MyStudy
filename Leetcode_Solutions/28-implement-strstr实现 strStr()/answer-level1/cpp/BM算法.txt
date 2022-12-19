```
class Solution {
public:
    int findChr(string needle , char chr , int j){
		for(int i=j - 1; i >= 0; i--){
			if(chr == needle[i]) return i + 1;
		}
		return 0;
	}
    //  BM算法
    int strStr(string haystack, string needle) {
        // 基本排除
		int target = needle.size();
		if (target == 0) return 0;
		int len = haystack.size();
		if (target > len) return -1;

        int i = target - 1;
        int j = target - 1;
        while(i < len && j >= 0){
            if(haystack[i] == needle[j]){
                if(j == 0) return i;
                j--;
                i--;
                continue;
            }
            if( i == len -1) return -1;
            if(findChr(needle,haystack[i],j) == 0){
	            i += target;
	            j = target - 1;
	            continue;
            }
            if(j > findChr(needle,haystack[i],j) - 1){
                i += target - findChr(needle,haystack[i],j);
                j = target - 1;
            }
        }
        return -1;
    }
};
```
