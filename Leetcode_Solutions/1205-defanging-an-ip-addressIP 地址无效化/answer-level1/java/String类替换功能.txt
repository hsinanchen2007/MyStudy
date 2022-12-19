String类字符串替换功能，但是“.”在正则表达式中代表任意字符，需要对其进行转义“\\.”

class Solution {
    public String defangIPaddr(String address) {
        String rep="[.]";
		String regex="\\.";
		String res=address.replaceAll(regex, rep);
		return res;
    }
}