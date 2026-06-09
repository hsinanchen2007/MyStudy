import java.util.Arrays;
class Solution {
    public int maxNumberOfBalloons(String text) {
        //设置一个数组，记录balon五个字符出现的次数
    	int[] balon = new int[5];
    	for(char ch:text.toCharArray()) {
    		switch(ch) {
    		case 'b': balon[0]++; break;
    		case 'a': balon[1]++; break;
    		case 'l': balon[2]++; break;
    		case 'o': balon[3]++; break;
    		case 'n': balon[4]++; break;
    		}
    	}
    	//lo数量需要除以2
    	balon[2] /= 2;
    	balon[3] /= 2;
    	Arrays.sort(balon);
    	return balon[0];
    }
}