```
public char findTheDifference(String s, String t) {
        for (int i = 0; i < s.length(); i++) {
			t=t.replaceFirst(s.charAt(i)+"", "");
		}
    return t.charAt(0);
}
```
