又学到了一个高效的技巧，以前大小写的转换一般都是先判断，后加减。现在直接异或32就可以了。首先大小写之间差了32，刚好是2的5次方，异或是不进位的加法。大写的二进制码第5位是0，小写的二进制码是1，所以异或就实现了大小写的转换。

这是验证的代码
```
public class A1 {
	public static void main(String[] args) {
		for(char ch = 'a', CH = 'A'; ch <= 'z' && CH <= 'Z'; ++ch, ++CH) {
			System.out.print(ch + "的二进制码： " + Integer.toBinaryString(ch));
			System.out.print(" 异或 " + Integer.toBinaryString((1 <<5)) + " 等于： ");
			System.out.println((char)(ch ^ (1 << 5)) + " 二进制码： " +Integer.toBinaryString(ch ^ (1 << 5)));
			System.out.print(CH + "的二进制码： " + Integer.toBinaryString(CH));
			System.out.print(" 异或 " + Integer.toBinaryString((1 <<5)) + " 等于： ");
			System.out.println((char)(CH ^ (1 << 5)) + " 二进制码： " +Integer.toBinaryString(CH ^ (1 << 5)));
			System.out.println();
		}
	}
}
```

题目代码
```
class Solution {
    public List<String> letterCasePermutation(String S) {
        List<String> ans = new ArrayList<String >();
        dfs(S.toCharArray(), ans, 0);
        return ans;
    }
    public void dfs(char[] arr, List<String > e, int index){
        if(index == arr.length) {
        	e.add(String.valueOf(arr));
        	return;
        }
        dfs(arr, e, index + 1);
        if(arr[index] < '0' || arr[index] > '9') {
        	arr[index] ^= 32;
        	dfs(arr, e, index + 1);
        }
    }
}
```


