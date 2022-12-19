```
import java.util.ArrayList;
import java.util.List;
/**
 * 题目：电话号码的字母组合
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 例如：输入："23" 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
 * @author lixiang
 * 这让我想到了一个多叉树所有路径的遍历，由此得到解法
 * 所以我的方法为将输入字符串转化为字符数组ch，建立一个对应的字符串数组str，用递归的方式将可能的字符一个个拼接进start
 * 就是要注意每一次都要新建一个临时的StringBuilder：temp来保存start作为根结点的情况，回溯时不要出错
 * 总用时1ms，占用36M内存,此解法仅作参考～
 */
public class Leetcode_16 {

	public List<String> letterCombinations(String digits) {
		List<String> re=new ArrayList<String>();
        if(digits==null || digits.isEmpty())
        	return re;
        char[] ch=digits.toCharArray();
        String[] str= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        StringBuilder start=new StringBuilder("");
        findAllWays(start,ch,0,str,re);
        return re;
    }
	
	private void findAllWays(StringBuilder start, char[] ch, int lo, String[] str, List<String> re) {
		if(lo==ch.length) {
			re.add(start.toString());	
		}else {
			int num=ch[lo]-48;
			for(int i=0;i<str[num].length();i++) {
				StringBuilder temp=new StringBuilder(start);
				temp.append(str[num].charAt(i));
				findAllWays(temp,ch,lo+1,str,re);
			}
		}	
	}

	public static void main(String[] args) {
		Leetcode_16 leet=new Leetcode_16();
		String digits="234";
		System.out.println(leet.letterCombinations(digits));
	}
}
```