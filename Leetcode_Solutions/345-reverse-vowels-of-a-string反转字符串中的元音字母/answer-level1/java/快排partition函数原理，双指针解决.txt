### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        Set<Character> set = new HashSet<>();
        putVowelsInSet(set);
        char[] ss = s.toCharArray();
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            while(!set.contains(ss[left])){
                left++;
                if(left == s.length() - 1){
                    break;
                }
            }
            while(!set.contains(ss[right])){
                right--;
                if(right == 0){
                    break;
                }
            }
            if(left > right){
                break;
            }
            swap(ss, left, right);
            left++;
            right--;
        }
        return new String(ss);
    }
    private void swap(char[] ss, int a, int b){
        char temp = ss[a];
        ss[a] = ss[b];
        ss[b] = temp;
    }
    private void putVowelsInSet(Set<Character> set){
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        set.add('A');
        set.add('E');
        set.add('I');
        set.add('O');
        set.add('U');
    }
}
```