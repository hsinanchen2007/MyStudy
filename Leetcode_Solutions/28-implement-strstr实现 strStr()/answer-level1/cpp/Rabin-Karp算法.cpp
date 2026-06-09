hash函数+检查
```
class Solution {
public:
    // 计算hash 
    int hash(string key , int j , int len){
		int sum = 0;
        for(int i  = 0; i < len; i++){
            sum += key[j + i];
        }
        return sum;
	}
    // 冲突检查
    bool check(string haystack , string needle , int address){
        for(int i = 0; i < needle.size(); i++){
            if(haystack[i + address] != needle[i]) return false;
        }
        return true;
    }
    //  Rabin-Karp算法
    int strStr(string haystack, string needle) {
        // 基本排除
        if(haystack == needle) return 0;
		int target = needle.size();
		if (target == 0) return 0;
		int len = haystack.size();
		if (target > len) return -1;

        // 模式字符串hash
        int temp = hash(needle,0,target);
        int result = 0;
        int i = 0;
        while(i < len - target + 1){
            result = hash(haystack,i,target);
            if(result == temp){
                if(check(haystack,needle,i)){
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
};
```
