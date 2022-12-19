### 解题思路
双指针，滑动窗口
Time: O(n)
Space: O(n)

### 代码

```java
class Solution {
    public String compressString(String S) {
        StringBuilder ans = new StringBuilder();
        int index1 = 0;
        int index2 = 0;
        char temp1 = 'c';
        char temp2 = 'c';
        while(index2 < S.length()){
            temp1 = S.charAt(index1);
            temp2 = S.charAt(index2);
            if(temp1 == temp2){
                index2++;
            }else{
                ans.append(temp1);
                ans.append(index2 - index1);
                index1 = index2;
            }
        }
        ans.append(temp1);
        ans.append(index2 - index1);
        if(ans.length() >= S.length())
            return S;
        return new String(ans);
    }
}
```