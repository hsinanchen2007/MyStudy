```
class Solution {
public:
    // 计算偏移量 
    int calShiftMat(string s , char chr){
    	int i = -1;
       	for(int temp = 0; temp < s.size() ; temp++){
       		if(s[temp] == chr) i = temp;
       	}
        return i;
    }
    int strStr(string haystack, string needle) {
        if (haystack == needle) return 0;
		int target = needle.size();
		if (target == 0) return 0;
		int len = haystack.size();
		if (target > len) return -1;

        int i = 0;
        int j = 0;
        int temp = 0;
        while(i < len && j < target){
            if(haystack[i] != needle[j]){
                if (i == len - 1) return -1;
                if(j == 0){
                    i++;
                    continue;
                }else{
                    if(i + target - j > len) return -1;
                    temp = calShiftMat(needle,haystack[i + target - j]);
                    if(temp == -1){
                        i++;
                    }else{
                        i +=target - j - temp;
                    	j = 0;
                    }
                }
            }else{
                if (j == target - 1) return i - j;
                i++;
                j++;
            }
        }
        return -1;
    }
};
```
