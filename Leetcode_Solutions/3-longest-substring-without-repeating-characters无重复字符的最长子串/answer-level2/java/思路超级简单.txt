1.使用双循环，第一个循环用于定位，第二个循环用于向后找元素
2.利用集合不能存储相同元素的特点，在每一次定位之后创建一个新的集合，如果成功添加元素
  则计数器加1，这样就可以得到不重复子串的长度。
3.有一个特殊情况是从某个字符开始到字符串末尾的不重复子串，所以要将这个子串的长度找出来
 并和上面的最大长度进行比较。条件是定位的位置加上计数器的长度等于字符长度。
4返回结果

### 代码

```java
class Solution {
     public static int lengthOfLongestSubstring(String s) {
         //if(s.length()==1) return 1;
        int count=0;
        int max = 0;
        int max2=0;
        for (int i = 0; i <s.length() ; i++) {
            HashSet<Character> hs = new HashSet<>();
            for(int j =i;j<s.length();j++){
                boolean flag = hs.add(s.charAt(j));
                if(flag){
                    count++;
                    if(i+count==s.length()) max2=count;
                }else{
                    if(max<count)  max=count;
                    count=0;
                    break;
                }
            }
        }

        return max>max2?max:max2;
    }
}
```