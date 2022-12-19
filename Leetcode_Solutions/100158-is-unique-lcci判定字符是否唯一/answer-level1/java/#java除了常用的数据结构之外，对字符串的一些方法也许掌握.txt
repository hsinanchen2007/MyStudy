### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.Set; 
import java.util.HashSet;
class Solution {
    public boolean isUnique(String astr) {
        //利用java中有一个lastIndexOf,字符最后一次出现的位置;
        // for(int i=0;i<astr.length();i++){
        //     if(astr.lastIndexOf(astr.charAt(i))!=i){
        //         return false;//该字符最后一次出现的位置不为当前位置那么他一定是有重复的了
        //     }
        // }
        // return true;
        //这里使用set集合无序不重复的特点
        Set set = new HashSet();
        for (int i = 0; i <astr.length() ; i++) {
            set.add(astr.charAt(i));
        }
        return set.size() == astr.length(); 
    }
}
```