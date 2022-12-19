### 解题思路
分五种情况考虑：1.两个字符串相同，true；2.两个字符串长度不相等且相差不等于1，是false；3.替换操作时；4.删除操作时；5插入操作时。
对于替换操作，长度是相等的，遍历每个字符，统计相同位置上字符不同的数量，看是否等于1；
对于删除操作，对长度短的进行遍历，统计相同位置字符是否相同，控制一个位置只能比较一次。
对于插入操作，与删除类似。

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        if (first.equals(second)){
            return true;
        }
        if (first.length()+1 != second.length() && second.length()+1 != first.length() && second.length() != first.length()){
            return false;
        }
        int count = 0;
        //替换
        if (first.length() == second.length()){
             for (int i = 0;i < first.length();i++){
                if(first.charAt(i) != second.charAt(i)){
                    count++;
                }
             }
             if (count==1){
                 return true;
             }
        }else if(first.length() > second.length()) {//删除
               int delIndex = 0;
               int n = 0;
               for (int j = 0;j < second.length();j++){
                 if(first.charAt(j+n) == second.charAt(j)){
                    delIndex++;
                 }else if( first.charAt(j+1) == second.charAt(j)) {
                     n++;
                     delIndex++;
                 }
               }
               if (delIndex==second.length()){
                   return true;
               }
        }else if (first.length() < second.length()){//插入
            int adIndex = 0;
            int k = 0;
            for (int m =0;m < first.length();m++){
                if (second.charAt(m+k) == first.charAt(m)){
                   adIndex++;
                }else if(second.charAt(m+1) == first.charAt(m)){
                  k++;
                  adIndex++;
                }
            }
            if (adIndex == first.length()){
                return true;
            }
        }
        return false;

    }
}
```