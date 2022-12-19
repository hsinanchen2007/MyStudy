### 解题思路

### 代码

```python []
class Solution:
    def compressString(self, S: str) -> str:
        if not S:
            return ""
        cnt = 0  # 计数
        ch = S[0]  # 记录当前字符，从第一个开始
        ans = ""  # 记录结果字符
        for c in S:   # 取S中的字符与当前字符比较
            if c == ch:  
                cnt += 1   # 相同，则次数加一
            else:
                ans += ch + str(cnt)   # 不同则结果=当前字符+次数字符
                ch = c   # 跳到这个不同字符继续循环
                cnt = 1  # cnt从1开始
        ans += ch+str(cnt)    
        return ans if len(ans)<len(S) else S
       # 没有变短，返回原先字符，变短了，返回压缩字符
```

```java []
class Solution {
    public String compressString(String S) {
        if (S.length() == 0){
            return "";
        }
        StringBuilder ans = new StringBuilder(); 
        // 创建一个字符序列可变的字符串ans存取结果
        char[] chars = S.toCharArray();
        // 将S转换为一个字符数组chars
        int cnt = 1;   //计数
        char temp = chars[0];
        for(int i=1;i<S.length();i++){
            if (temp==chars[i]){   // 当前字符等于取的第一个字符
                cnt++;   // 计数
            }
            else{
                ans.append(temp);   // StringBuilder方法用append()加
                ans.append(cnt);
                temp = chars[i];
                cnt = 1;
            }
        }
        ans.append(temp);
        ans.append(cnt);
        if(ans.length()<S.length()){
            return ans.toString();   	
      //就可以调用它的toString()方法将其转换为一个String对象。
        }
        else{
            return S;
        }

    }
}
```
时间复杂度O(n)
空间复杂度O(1)