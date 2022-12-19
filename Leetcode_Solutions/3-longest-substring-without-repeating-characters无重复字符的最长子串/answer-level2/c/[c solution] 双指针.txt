### 解题思路

今天面试题，熟练度不够真的很难紧张环境下写出来，晚上自己琢磨琢磨还是有思路的。

继续吧 go！！！

### 代码

```c


#define MAX(a,b)(a>b?a:b)

// 判断s[right] 在[left, right)是否重复
bool isRepeat(char* s, int left , int right){
    if(left >= right){
        return false;
    }
    while(left < right){
        if(s[left++] == s[right]){
            return true;
        }
    }
    return false;
}


int lengthOfLongestSubstring(char * s){
    if(strlen(s) <= 0){
        return 0;
    }

    int max = 0 , left = 0 , right = 0 , len = strlen(s);
    while(left < len && right < len){
        if(!isRepeat(s,left,right)){
            right++;
            max = MAX(max, (right - left ));
        }else{
            left++;
        }
    }
    return max;
}
```