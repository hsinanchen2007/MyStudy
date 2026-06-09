/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/4
 *
 * 解题思路: hash 表解决 1. java自带hashmap  2. 自己构造一个26个空间字符数组进行散列存储
 *
 */
```

 public boolean canConstruct(String ransomNote, String magazine) {
    HashMap<Character , Integer> hashMap = new HashMap<>();

    char[] magazine_arr = magazine.toCharArray();
    char[] ransomNote_arr = ransomNote.toCharArray();
    for(int i = 0; i < magazine.length();i++){
        if(hashMap.containsKey(magazine_arr[i])){
            hashMap.put(magazine_arr[i],hashMap.get(magazine_arr[i])+1);
        }else{
            hashMap.put(magazine_arr[i],1);
        }
    }

    for(int i = 0;i < ransomNote.length();i++){
        if(hashMap.containsKey(ransomNote_arr[i]) && hashMap.get(ransomNote_arr[i]) > 0){
            hashMap.put(ransomNote_arr[i],hashMap.get(ransomNote_arr[i]) - 1);
        }else{
            return false;
        }
    }
    return true;
}

public boolean canConstruct2(String ransomNote, String magazine) {
    char[] magazine_arr = magazine.toCharArray();
    char[] ransomNote_arr = ransomNote.toCharArray();
    char[] letter = new char[26];

    for(int i = 0;i < magazine_arr.length;i++){
        letter[magazine_arr[i] - 'a']++;
    }

    for(int i = 0; i< ransomNote_arr.length;i++){
        if(letter[ransomNote_arr[i] - 'a'] == 0){
            return false;
        }else{
            letter[ransomNote_arr[i] - 'a']--;
        }
    }
    return true;
}

```