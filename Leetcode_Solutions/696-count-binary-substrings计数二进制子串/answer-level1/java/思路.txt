### 解题思路
 cur，pre分别记录当前字符，前一个字符的出现次数,每次分别比较是否可以重复

### 代码

```java
class Solution {
    public int countBinarySubstrings(String s) {
        //初始化
        int n=s.length()-1,pre=0,cur=1;
        int ans=0;
        //遍历数组
        for(int i=0;i<n;i++){
            if(s.charAt(i)==s.charAt(i+1)){
                cur++;           
            }
            else{
                pre=cur;
                cur=1;

            }
         if(pre>=cur){
             ans++;
         }

        }

        return ans;

    }
}
```