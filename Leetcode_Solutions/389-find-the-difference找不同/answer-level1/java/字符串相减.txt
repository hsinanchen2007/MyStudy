本题目的只是找出多余的那个字符，那我们可以暴力的找出asci码差值。
执行用时 :1 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :37.4 MB, 在所有 java 提交中击败了44.71%的用户
public char findTheDifference(String s, String t) {
        char []sArray = s.toCharArray();
        char []tArray = t.toCharArray();
        
        int ansiS = 0;
        for (int i = 0; i < sArray.length; i ++) {
        	int charNum = (int) tArray[i] - (int) sArray[i];
        	ansiS += charNum;
        }
        
        ansiS += (int) tArray[tArray.length - 1];
        
        return (char) ansiS;
    }
