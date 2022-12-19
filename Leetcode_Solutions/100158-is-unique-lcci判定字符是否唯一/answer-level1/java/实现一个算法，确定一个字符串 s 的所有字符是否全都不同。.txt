### 解题思路小菜鸟的暴力算法

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] arr=astr.toCharArray();
        for(int i=0;i<arr.length-1;i++){
            for(int j=i+1;j<arr.length;j++){
                if(arr[i]==arr[j])  return false;
            }
        }
        return true;
    }
}
```
### 
使用hash表
###
```
public static boolean isUnique(String str) {
	char[] arr=str.toCharArray();
	Set<Character>set=new HashSet<Character>();
	for(char a:arr) {
		if(set.contains(a))  return false;
		set.add(a);
	}
	return true;
```
