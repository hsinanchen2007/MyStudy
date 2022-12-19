### 解题思路
总的想法就是找交集吧。

### 代码

```java
class Solution {
    public List<String> commonChars(String[] A){
        int[] count = new int[26];
        for(int i = 0; i < 26; i++) count[i] = Integer.MAX_VALUE;

        for(String str : A){
            int[] temp = new int[26];
            for(int i = 0; i < 26; i++) temp[i] = 0;
            
            for(char c : str.toCharArray()) temp[c-'a']++;

            for(int i = 0; i < 26; i++) count[i] = Math.min(count[i], temp[i]);
        }

        List<String> ans =  new ArrayList<String>();
        for(int i = 0; i < 26; i++){
            while(count[i] > 0){
                ans.add("" + (char)('a' + i));
                count[i]--;
            }
        }
        return ans;
    }
}


// class Solution {
//     public List<String> commonChars(String[] A){

//         int[] counter = new int[26];
//         for(char c : A[0].toCharArray()){
//             counter[c - 'a']++; // 为了不让index超过length大小,将char变成数字在数组中
//         }

//         for(int i = 1; i < A.length; i++){
//             int[] temp =  new int[26];
//             for(char c : A[i].toCharArray()){
//                 temp[c - 'a']++;
//             }

//             for(int j = 0; j < 26; j++){
//                 if(counter[j] > temp[j]){
//                     counter[j] = temp[j];
//                 }
//             }
//         }

//         LinkedList<String> ans = new LinkedList<>();
//         for(int h = 0; h < 26; h++){
//             while(counter[h]-- > 0){
//                 ans.addLast("" + (char)('a' + h));
//             }
//         }
//         return ans;
//     }
// }


// class Solution {
//     public List<String> commonChars(String[] A) {

//         String start = A[0];
//         int len = A.length;

//         List<String> ans = new ArrayList<>();

//         for(char temp : start.toCharArray()){
//             // String cur = Character.toString(temp);
//             String cur = "" + temp;
            
//             for(int j = 1; j < len; j++){
//                 if(!A[j].contains(cur)){
//                     break;
//                 }
                
//                 if(j == len - 1){
//                     ans.add(cur);
//                 }
//                 A[j] = A[j].replaceFirst(cur, "");
//             }

//         }

//         return ans;
//     }
// }
```