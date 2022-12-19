```
class Solution {
    public String reverseVowels(String s) {
        HashSet<Character>set=new HashSet<>();
	set.add('A');set.add('a');
        set.add('E');set.add('e');
        set.add('I');set.add('i');
        set.add('O');set.add('o');
        set.add('U');set.add('u');
	int low=0,high=s.length()-1;
	char ch[]=s.toCharArray();
	while(low<high){
		while(low<high&&!set.contains(ch[low]))
			low++;
		char temp=ch[low];
		while(low<high&&!set.contains(ch[high]))
			high--;
		ch[low]=ch[high];
		ch[high]=temp;
            low++;high--;
	}
	return new String(ch);		
    }
}
```