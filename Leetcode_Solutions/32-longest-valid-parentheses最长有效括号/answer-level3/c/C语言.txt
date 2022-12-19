### 解题思路

![image.png](https://pic.leetcode-cn.com/163e3da16b34cbf097b12f8e7f232983b7755b4e9ba34e504b7ea9556a8db045-image.png)



### 代码

```c
int longestValidParentheses(char * s){
    int i = 0, maxLength = 0, left = 0, currentLength = 0, tempLength = 0;
    while (s[i] != '\0') {
        if(s[i] =='('){
            left++;
        }else{
            left--;
        }
        if(left < 0){
            currentLength = 0;
            tempLength = 0;
            
            left = 0;
        }else if(left == 0){
            tempLength++;
            currentLength = currentLength + tempLength;
        
            tempLength = 0;
            if(currentLength > maxLength){
                maxLength = currentLength;
            }
        }else{
            tempLength ++;
            if(s[i] ==')'){
                int leng = lengthOfAvailable(s, i);
                if(leng > maxLength){
                    maxLength = leng;
                }
            }
        }
        i++;
    }
    
    return maxLength;
}


int lengthOfAvailable(char *s, int index){
    int length = 0;
    int rightNum = 0;
    while (index > 0) {
        if(s[index] == ')'){
            rightNum ++;
        }else{
            rightNum --;
        }
        if(rightNum < 0){
            return length;
        }
        length++;
        index --;
    }
    return length;
}
```