### 解题思路
8ms，97%
从后往前遍历，遇到更大的字符交换指针。
遇到相同的字符，先不着急比较后续的字符，看看它前面的一个是不是一样的，一样的就continue，直到不一样或者到头了，再比较。

### 代码

```java
class Solution {
    public String lastSubstring(String s) {

        char[] str = s.toCharArray();
        int index = str.length-1;
        int max = 0;

        for(int i=str.length-1;i>=0;i--){
            if(str[i]-'a'>max){
                index = i;
                max = str[i]-'a';
            }else if(str[i]-'a'==max){
                if(i-1>=0&&str[i]==str[i-1]) continue;//非常关键！！！
                int temp = index;
                index = i;
                max = str[i]-'a';
                for(int j=i,k=temp;j<str.length&&k<str.length;j++,k++){
                    if(str[k]-'a'==str[j]-'a') continue;
                    if(str[k]-'a'>str[j]-'a'){
                        index = temp;
                        max = str[index]-'a';
                        break;
                    }else if(str[k]-'a'<str[j]-'a'){
                        break;
                    }
                }
            }
        }

        return s.substring(index);
    }
}
```