奇数个就加n-1，偶数个就都加上n，如果有某个字母是奇数个，最后要在总数上加1
```
class Solution {
public:
    int longestPalindrome(string z) {
        int a[128]= {0};
        for(char m: z){
            a[m] += 1;
        }
        int s = 0;
        int flag = false;
        for(int i=0;i<128;i++){
            if(a[i]==0)continue;
            if(a[i]%2==0) s+=a[i];
            else {
                flag = true;
                s += a[i]-1;
            }

        }
        if(flag) s++;
        return s;

    }
};
```
