### 解题思路
必须从末尾开始遍历，非空开始计数，再次为空就保存该数字，退出循环

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int cnt = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == ' '){
                cnt = 0;
            }else{
                cnt++;
                if( i - 1 >= 0 && s.charAt(i-1) == ' '){
                    break;
                }
            }
        }
        return cnt;
    }
}
```