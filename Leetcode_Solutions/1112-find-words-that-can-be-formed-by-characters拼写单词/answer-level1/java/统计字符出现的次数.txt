### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[]nums=new int[26];
        for(int i=0;i<chars.length();i++){
            nums[chars.charAt(i)-'a']++;
        }
        int result=0;
        for(String str:words){
            char[]charArray=str.toCharArray();
            int[]temp=new int[26];
            boolean flag=true;
            if(str.length()>chars.length()){
                continue;
            }
            for(int i=0;i<charArray.length;i++){
                temp[charArray[i]-'a']++;
                if(temp[charArray[i]-'a']>nums[charArray[i]-'a']){
                    flag=false;
                    break;
                }
            }
            result=result+(flag?str.length():0);
        }
        return result;
    }
}
```