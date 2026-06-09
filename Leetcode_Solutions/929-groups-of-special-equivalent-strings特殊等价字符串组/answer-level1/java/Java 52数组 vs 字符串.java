### 解题思路

特殊等价字符串，思路就是将字符串的偶数位和奇数位分为两个字符串，并排序，再合在一起加入到集合中

第一种办法空间小，第二种办法速度快

### 代码

```java
class Solution {
    public int numSpecialEquivGroups(String[] A) {
		Set<String> set = new HashSet<>();
		for(String str:A) {
			int count[] = new int[52];
			for(int i=0;i<str.length();i++) {
				if(i%2==0) count[str.charAt(i)-'a']++;
				else count[str.charAt(i)-'a'+26]++;
				
			}
			set.add(Arrays.toString(count));
		}
		return set.size();

    }
}
```

```java
	public static int numSpecialEquivGroups(String[] A) {
		Set<String> set = new HashSet<>();
		for(String str:A) {
			String even = "";
			String odd = "";//奇数
			for(int i=0;i<str.length();i++) {
				if(i%2==0) even+=str.charAt(i);
				else {
					odd+=str.charAt(i);
				}
			}
			char charsE[] = even.toCharArray();
			char charsO[] = odd.toCharArray(); 
			Arrays.sort(charsE);
			Arrays.sort(charsO);
			set.add(new String(charsE)+new String(charsO));
		}
		return set.size();
	}
```