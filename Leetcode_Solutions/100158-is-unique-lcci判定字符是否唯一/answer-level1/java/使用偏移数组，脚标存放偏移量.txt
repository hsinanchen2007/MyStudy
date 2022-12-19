### 解题思路
1. 题目给出的都是小写字母，所以如果遇到特殊符号和大写肯定是不适用的
2. 使用一个固定空间的26个数字数组，填充值为-1
3. 然后计算char类型的偏移量，a从97开始，z到122
4. 然后用char - 97 去找脚标，只要遇到重复的，立刻return false
5. 都找不到就return true啦

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
       // 放26个英文字母的
        int[] seq = new int[26];
        Arrays.fill(seq,-1);
        char[] sub = astr.toCharArray();
        for(int i=0;i<sub.length;i++){
            char c = sub[i];
            if(seq[c-97] == c){
                return false;
            }else{
                seq[c-97] = c;
            }
        }
        return true; 
    }
}
```