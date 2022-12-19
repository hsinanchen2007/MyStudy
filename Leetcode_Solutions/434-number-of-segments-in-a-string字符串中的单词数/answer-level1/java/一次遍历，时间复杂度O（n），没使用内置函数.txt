使用count进行计数，flag来标志遇到空格的时候是否是一个单词的结束，是否给计数器加一，加一后再把标志位flag置0
如果最后的字符串不以空格结尾，遍历结束后，如果flag是1，则给计数器再加一
```
public class Solution {
    public int countSegments(String s) {
    	if(s.length()==0) {return 0;}
    	int count=0;
    	int flag=0;
        for(char c:s.toCharArray()) {
        	if(c==' '&& flag==0) {
        		continue;
        	}else if(c!=' ') {
        		flag=1;
        	}else if (c==' ' && flag==1) {
				count++;
				flag=0;
			}
        }
        if(flag==1) {
        	count++;
        }
        return count;
    }
}
```
