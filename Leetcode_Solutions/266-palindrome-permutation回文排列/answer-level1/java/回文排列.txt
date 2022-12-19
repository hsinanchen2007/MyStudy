### 解题思路
①创建一个HashMap,暂时存放每个字符出现的次数
②奇偶检验：字符出现次数如是偶数及余数为1时为回文

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
       if(s==null||s==""){
            return false;
        }
        char ss[]=s.toCharArray();
        HashMap<Character,Integer> hashMap = new HashMap<>();
        for(int i=0;i<ss.length;i++){
            if(hashMap.containsKey(ss[i])){
                int temp = hashMap.get(ss[i])+ 1;
                hashMap.put(ss[i],temp);
            }else {
                hashMap.put(ss[i],1);
            }
        }
        return hw(hashMap);
    }

   private static boolean hw(HashMap<Character,Integer> hashMap){
        int oddOrEven = 0;
        if (hashMap.size()==1){
            return true;
        }
        for(Integer value:hashMap.values()){
            oddOrEven += value%2;
        }
        if(oddOrEven==0||oddOrEven==1){
           return true;
        }else{
           return false;
        }
    }
}
```