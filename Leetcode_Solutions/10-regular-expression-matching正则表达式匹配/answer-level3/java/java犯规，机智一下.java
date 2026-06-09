```
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Solution {
	 public boolean isMatch(String s, String p) {
		 Pattern par = Pattern.compile(p);
		 Matcher m = par.matcher(s);
		 if(m.find()) {
			 if(m.group(0).toString().equals(s)) {
				 return true;
			 }else {
				 return false;
			 }
		 }else {
			 return false;
		 }
	 }
}
```
