### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        int len1 = Math.max(first.length(), second.length());
        int len2 = Math.min(first.length(), second.length());
        if (len1 - len2 > 1)
            return false;

        //first为长字符串，second为短字符串
        if (len1 != first.length()){
            String tmp = first;
            first = second;
            second = tmp;
        }

        int count=0;
        //分两种情况
        if(len1==len2){
            for (int i=0;i<len1;i++){
                if(first.charAt(i)!=second.charAt(i))
                    count++;
                if(count>1)return false;
            }
        }else {
            for(int i=0,j=0;i<len2;j++){
                if(count>1)return false;
                if(first.charAt(j)!=second.charAt(i)){
                    //不相同只移动长字符串的指针，把for改成while循环应该好些
                    count++;
                    continue;
                }
                i++;
            }
        }
        return true;
    }
}
```