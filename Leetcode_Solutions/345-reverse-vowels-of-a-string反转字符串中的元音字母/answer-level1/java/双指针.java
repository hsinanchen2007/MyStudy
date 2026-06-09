1. 两个指针分别从首尾遍历，
2. 当有一方是元音字母时，暂停移动，
3. 直到双方都是元音字母时，交换两个元音，并重新开始移动
```
class Solution {
    public String reverseVowels(String s) {
        // 元音字母 a e i o u
        if(s==null||s.length()<=1)
            return s;
        int i=0,j=s.length()-1;
        List<Character> vowel=Arrays.asList('a','e','i','o','u','A','E','I','O','U');
        char[] arr=s.toCharArray();
        while(i<j){
            if(!vowel.contains(arr[i]))// 如果是元音，暂停移动
                i++;
            if(!vowel.contains(arr[j]))// 如果是元音，暂停移动
                j--;
            if(vowel.contains(arr[i])&&vowel.contains(arr[j])){// 首尾都找到元音
                // 交换元音的位置
                char temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                // 重新开始移动
                i++;j--;
            }
        }

        return new String(arr);
    }
}
```
