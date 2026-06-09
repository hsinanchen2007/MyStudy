### 解题思路
统计每个单词个数，然后比较

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        if(words==null || words.length==0 || chars == null){
            return 0;
        }
        int[] c = new int[26];
        char[] arr = chars.toCharArray();

        for(int i=0;i<arr.length;i++){
            c[arr[i]-'a'] ++;
        }
        int sum = 0;
        for(int j=0;j<words.length;j++){
            int[] cc = new int[26];
            cc = Arrays.copyOf(c,26);

            String tmp = words[j];
            char[] a = tmp.toCharArray();
            
            boolean flag = true;
            for(int k=0;k<a.length;k++){
                if(cc[a[k]-'a']<1){
                    flag = false;
                    break;
                }else{
                    cc[a[k]-'a']--;
                }
            }
            if(flag){
                sum+=tmp.length();
            }
        }
        return sum;
    }
}
```