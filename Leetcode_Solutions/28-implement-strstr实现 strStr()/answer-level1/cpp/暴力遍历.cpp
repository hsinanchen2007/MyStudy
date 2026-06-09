

第二次独立解题，撒花

```
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle==""){ // needle是0情况
            return 0;
        }
        int len = needle.size();     
        int len1 = haystack.size();
        if(len>len1){ // needle比haystack长情况
            return -1;
        } 
        for(int i = 0; i<haystack.size()-len+1; i++){ // 从0开始，取needle长度的字符串出来和needle对比
            string s = "";
            for(int j = i; j<i+len; j++){ // 取needle长度字符串
                s+=haystack[j];
            }
            if(s==needle){
                return i;
            }
        }
        return -1;
    }
};
```
