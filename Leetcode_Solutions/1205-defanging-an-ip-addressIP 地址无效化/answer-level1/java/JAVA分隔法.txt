先利用 . 把字符串分隔为长度为4的数组，主要注意 "." 的转义
之后字符串拼接出来答案即可
```
class Solution {
    public String defangIPaddr(String address) {
        String str = "";
		String[] split = address.split("[.]");  //根据.分隔为长度为4的数组，注意不能直接使用 "." 需要用 [] 包括住 . 或者利用转义字符 "\\." 效果是一样的
		for (int i = 0; i < 4; i++) {
			if(i < 3)
				str += split[i] += "[.]"; //字符串拼接
			else
				str += split[i];
		}
        return str;
    }
}
```
