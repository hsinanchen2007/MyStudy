```
class Solution {
    public  String reverseVowels(String s) {
        char[] arr = s.toCharArray();
        int index1 = 0;
        int index2 = arr.length - 1;
        HashSet<Character> Yuan = new HashSet<Character>();
        Yuan.add('a');
        Yuan.add('e');
        Yuan.add('i');
        Yuan.add('o');
        Yuan.add('A');
        Yuan.add('E');
        Yuan.add('I');
        Yuan.add('O');
        Yuan.add('U');
        Yuan.add('u');
        while (index1 < index2)
        {
            if (Yuan.contains(arr[index1]) && Yuan.contains(arr[index2])){
                char c;
                c = arr[index1];
                arr[index1] = arr[index2];
                arr[index2] = c;
                index1++;
                index2--;
            }
            else if (Yuan.contains((arr[index1]))){
                index2--;
            }else if (Yuan.contains(arr[index2])){
                index1++;
            }
            else {
                index1++;
                index2--;
            }

        }
    
        String str = String.valueOf(arr);
        return str;
    }
 
}
```
