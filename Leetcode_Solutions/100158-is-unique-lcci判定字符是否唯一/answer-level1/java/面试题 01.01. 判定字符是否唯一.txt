### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int len=astr.length();
        if(len==0||len==1)return true;
        String res=astr.substring(0,1);
        for(int i=1;i<len;i++){
            String subs=astr.substring(i,i+1);
            if(res.contains(subs))return false;
            res+=subs;
        }
        return true;
    }
}
```