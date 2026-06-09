### 解题思路
双指针

处理字符串的经典题，建议此题换着不同写法多练习几次，字符串我处理不好
### 代码

```java
class Solution {
    private final static HashSet<Character> vowels=new HashSet<>(Arrays.asList('a','e','i','o','u','A','E','I','O','U'));//如何创建HashSet并添加元素，这种写法需要适应

    public String reverseVowels(String s) {
        if(s==null)return null;
        int i=0,j=s.length()-1;//字符串获取长度和数组方式不同
        char[] result=new char[s.length()];
        while(i<=j){
            char ci=s.charAt(i);
            char cj=s.charAt(j);
            if(!vowels.contains(ci)){
                result[i++]=ci;
            }
            else if(!vowels.contains(cj)){
                result[j--]=cj;
            }
            else{
                result[i++]=cj;
                result[j--]=ci;
            }
        }
        return new String(result);//这里假如分成两行怎么写？思考一下
    }
}
```