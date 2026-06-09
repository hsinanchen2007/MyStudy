```
//Brute Force: BF Algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {        
        //利用双指针
        int m = needle.size();
        if(!m) return 0;

        int n = haystack.size();
        for(int i = 0; i < n - m + 1; i++){
            for(int j = 0; j < m; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
                if(j == m-1){
                    return i;
                }
            }
        }
        return -1;
    }
};
```

```
//Rabin Krap: RF Algorithm
class Solution {
    int BASE = 1000000;
public:
    int strStr(string haystack, string needle) {        
        int m = needle.size();
        if(!m) return 0;

        //31^m
        int power = 1;
        for(int i = 0; i < m; i++){
            power = (power * 31) % BASE;
        }

        int target = 0;
        for(int i = 0; i < m; i++){
            target = (target * 31 + needle[i]) % BASE;            
        }
        int hashCode = 0;
        for(int i = 0; i < haystack.size(); i++){
            //abc + d
            hashCode = (hashCode * 31 + haystack[i]) % BASE;
            if(i < m-1) continue;

            //abcd - a
            if( i >= m){
                hashCode = hashCode - power * haystack[i-m] % BASE;
                if(hashCode < 0) hashCode += BASE;                
            }
            //double check the string
            if(hashCode == target){
                // if(haystack.substr(i - m + 1, m).compare(needle) == 0){
                //     return i - m + 1;
                // };
                string str ;                
                if(haystack.substr(i - m + 1, m) == needle){
                    return i - m + 1;
                };
            }
        }
        return -1;
    }    
};
```
分别利用双指针进行暴力解算Brute Force 和利用Hash Function的Rabin Krap算法进行结算.

欢迎留言讨论 to Bill