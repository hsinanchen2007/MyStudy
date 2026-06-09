### 解题思路
抹去字符的差异，保留结构信息。

每个位置的字符用数字替代。
这个数字是从左到右按需生成，同一个位置，会是相同的数字，如果是同构的话。

生成之后，判断是否相等即可。

### 代码

```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s==null&& t==null || s!=null&&s.equals(t)){
            return true;
        }else if(s==null || t==null){
            return false;
        }

        String s1 = getUniformStr(s);
        String t1 = getUniformStr(t);

        return s1.equals(t1);   
    }

    String getUniformStr(String s){
        int[] charIdArray = new int[256];
        Arrays.fill(charIdArray,(int)0);
        int charId =1;

        StringBuilder strBld=new StringBuilder();
        for(int i =0;i<s.length();i++){
            int charIndex = s.charAt(i)+128; //char could be negative
            if(charIdArray[charIndex]==(int)0){
                charIdArray[charIndex]=charId++;
            }
            strBld.append(charIdArray[charIndex]);
        }
        return strBld.toString();
    }
    
}

```