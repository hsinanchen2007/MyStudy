**方法一：一次循环遍历**
```
class Solution {
    /**
    * 思路：
    * (1) 如果原字符串长度小于等于2，则压缩后长度不会变短，直接返回原字符串；
    * (2) 创建StringBuilder用来拼接压缩后的字符串，
    *       初始拼接原字符串第一个字符，并记录初始拼接长度值为1；
    * (3) 从原字符串第二个字符开始遍历，判断当前字符与前一个字符是否相同，
    *       如果相同，则记录的拼接长度值+1，
    *       如果不同，则拼接记录的拼接长度值并拼接新的字符，然后将记录的拼接长度值置为1；
    * (4) 遍历结束后拼接最后一个记录的拼接长度值然后和原字符串长度比较，
    *       如果变短就返回新字符串，否则返回原字符串。
    */
    public String compressString(String S) {
        if(S.length() <= 2){
            return S;
        }
        StringBuilder sb = new StringBuilder();
        int nums = 1;
        sb.append(S.charAt(0));
        for(int i = 1; i < S.length(); i++){
            if(S.charAt(i) == S.charAt(i-1)){
                nums += 1;
            }else {
                sb.append(nums).append(S.charAt(i));
                nums = 1;
            }
        }
        return sb.append(nums).length() < S.length() ? sb.toString() : S;
    }
}
```

**方法二：双指针**
```
class Solution {
    /**
    * 思路：
    * 同方法一，用两个指针区间来记录要拼接的压缩子串
    */
	public String compressString(String S) {
        if(S.length() <= 2){
            return S;
        }
		int N = S.length();
		int i = 0;
		StringBuilder sb = new StringBuilder();
		while (i < N) {
			int j = i;
			while (j < N && S.charAt(j) == S.charAt(i)) {
				j++;
			}
			sb.append(S.charAt(i));
			sb.append(j - i);
			i = j;
		}
		return sb.length() < S.length ? sb.toString() : S;
	}
}
```
