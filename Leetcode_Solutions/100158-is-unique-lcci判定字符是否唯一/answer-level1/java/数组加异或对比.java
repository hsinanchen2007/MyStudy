### 解题思路
一开始想到的就是用set。但是要创建很多对象。性能一定不是最优。
也想到用subString。但是字符串操作一定不是最优。
然后想到先转化为字符。然后一一对比。就想到了先getBytes。


### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        if(astr==null||astr.length()<=1)return true;
        byte[] chars = astr.getBytes();
        for(int i=0;i<chars.length;i++){
            int a = chars[i];
            for(int j=i+1;j<chars.length;j++){
                int b = chars[j];
                if((a^b)==0){
                	return false;
                }
            }
        }
        return true;
    }
}
```