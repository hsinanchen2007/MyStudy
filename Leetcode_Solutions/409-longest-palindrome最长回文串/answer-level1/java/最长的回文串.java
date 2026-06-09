### 解题思路
此处撰写解题思路
1. 遇到有关字母的问题要想到Ascii码直接创建数组的方法来存储相应的值
2. 除以一个数再乘以一个数，对偶数来说没变化，对奇数来说，会减一
### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
    //     Map<Character,Integer> map=new HashMap<>();
    //     Set<Character> set=map.keySet();
    //     char ch[]=s.toCharArray();
    //     int result=0;
    //     int ii=0;
    //     // for(int i=0;i<s.length();i++){
    //     //     char c=s.charAt(i);
    //     //     map.put(c,map.getOrDefault(c,0)+1);
    //     // }
    //     for(int i=0;i<ch.length;i++){
    //         if(map.containsKey(ch[i])){
    //             int temp=map.get(ch[i]);
    //             temp++;
    //             map.put(ch[i],temp);
    //         }else{
    //             map.put(ch[i],1);
    //         }
    //     }
    //     for(Character c:map.keySet()){
    //         if(map.get(c)%2==0){
    //             result+=map.get(c);
    //         }else if(map.get(c)/2>0){
    //             result+=map.get(c)-1;
    //             ii++;
    //         }else{
    //             ii++;
    //         }
    //     }
    //     if(ii!=0){
    //         result+=1;
    //     }
    //     return result;

    // }
     if (s == null||s.length()==0) return 0;
        
        int[] f = new int[58];
        for (char ch : s.toCharArray()) {
            f[ch - 'A']++;
        }
        int res = 0, odd = 0;
        for (int num : f) {
            if (num == 0) continue;
            res += num / 2 * 2;
            if (num % 2 == 1) {
                odd = 1;    
            } 
        }
        res += odd;
        return res;
    }
}
```