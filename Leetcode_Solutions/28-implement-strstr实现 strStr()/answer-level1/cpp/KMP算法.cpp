```
class Solution {
public:
    int showNext(string s, int target) {
		string str1, str2;
		int num = 0;
		bool status = false;
		for(int j = 0;j < target-1;j++){
			if(s[j] != s[j+1]){
				status = true;
				break;
			}
		}
        if(!status){
            return target - 1;
        }
        for (int i = 0; i < target / 2; i++) {
				str1 = str1 + s[i];
				str2 = s[target - i - 1] + str2;
				if (str1 == str2) {
					num = str1.size();
			}
		}	
		return num;
	}
	int strStr(string haystack, string needle) {
		if (haystack == needle) return 0;
		int target = needle.size();
		if (target == 0) return 0;
		int len = haystack.size();
		if (target > len) return -1;

		int i = 0;
		int j = 0;
		int temp;
		while (i < len && j < target) {
			if (needle[j] != haystack[i]) {
				if (i == len - 1) return -1;
				if (j == 0) {
					i++;
                    continue;
				}
                temp = showNext(needle, j);
                j = temp ? temp : 0;
			}
			else {
				if (j == target - 1) return i - j;
				i++;j++;
			}
		}
		return -1;
	}
};
```
