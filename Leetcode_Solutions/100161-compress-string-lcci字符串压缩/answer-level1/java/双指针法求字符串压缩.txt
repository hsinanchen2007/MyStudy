### 解题思路
aabcccccaa
左指针left=0 右指针right=1
**StringBuilder**
StringBuilder sb 首先放入元素left
while(left<S.length()){
    如果S.charAt(left) == S.charAt(right)，right右移
    反之首先sb加入长度right-left，其次left=right，right++，sb再加入left元素
}
最后还需要***str.append(right - left);***
**例子**
S：aabcccccaa sb=a,left = 0,right = 1
1. sb=a,left = 0,right = 2
2. sb=a2,left = 2,right=3
3.  sb=a2b1,left = 3,right=4
4. sb=a2b1,left = 3,right=5
5. sb=a2b1,left = 3,right=6
6. sb=a2b1,left = 3,right=7
7. sb=a2b1,left = 3,right=8
8. sb=a2b1c5a,left = 8,right=9
9. sb=a2b1c5a,left = 8,right=10
10. sb=a2b1c5a2,left = 8,right=9
### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() <= 2){
            return S;
        }
        StringBuilder str = new StringBuilder();
        int left = 0;
        int right = 1;
        str.append(S.charAt(left));
        while(right < S.length()){
            if(S.charAt(left) == S.charAt(right)){
                right++;
            }else{
                str.append(right - left);
                left = right++;
                str.append(S.charAt(left));               
            }
        }
        str.append(right - left);
        if(str.length() >= S.length()){
            return S;
        }
        return str.toString();
    }
}
```